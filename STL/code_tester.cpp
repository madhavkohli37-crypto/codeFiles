#include <bits/stdc++.h>
using namespace std;

// ----------------- Brute force simulator -----------------
struct State {
    int t;
    int side;
    int pts;
    State() {}
    State(int _t, int _side, int _pts) : t(_t), side(_side), pts(_pts) {}
};

int brute(int n, int m, const vector<int>& a, const vector<int>& b) {
    // build requirement map: at time x, required side or -1 if none
    vector<int> req(m + 1, -1);
    for (int i = 0; i < n; ++i) req[a[i]] = b[i];

    int best = -1;
    queue<State> q;
    q.push(State(0, 0, 0)); // start at time=0, side=0, points=0

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.t > m) continue; // shouldn't happen but safe

        // Check requirement at current time BEFORE making decision to move.
        if (cur.t <= m && req[cur.t] != -1 && cur.side != req[cur.t]) {
            continue; // this path is invalid
        }

        if (cur.t == m) {
            best = max(best, cur.pts);
            continue;
        }

        // stay
        q.push(State(cur.t + 1, cur.side, cur.pts));
        // run to other side (earn a point)
        q.push(State(cur.t + 1, 1 - cur.side, cur.pts + 1));
    }

    return best;
}

// ----------------- Your formula code (non-mutating) -----------------
int your_code(int n, int m, vector<int> a, vector<int> b) {
    // make copies that include the initial (0,0)
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    int points = 0;
    for (int i = 1; i <= n; ++i) {
        if ((a[i] + a[i - 1] + b[i - 1] + b[i]) % 2 == 0)
            points += (a[i] - a[i - 1]);
        else
            points += (a[i] - a[i - 1] - 1);
    }
    if (a[n] < m) points += (m - a[n]);
    return points;
}

// ----------------- Test harness -----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // deterministic random
    mt19937 rng(123456);

    for (int m = 1; m <= 10; ++m) { // small m for brute force
        for (int n = 0; n <= m; ++n) {
            // run many random samples for this (n,m)
            for (int trial = 0; trial < 2000; ++trial) {
                // generate n distinct times in [1..m]
                vector<int> times;
                times.reserve(m);
                for (int x = 1; x <= m; ++x) times.push_back(x);
                shuffle(times.begin(), times.end(), rng);
                times.resize(n);
                sort(times.begin(), times.end());

                vector<int> a = times;
                vector<int> b(n);
                for (int i = 0; i < n; ++i) b[i] = rng() & 1;

                int brute_ans = brute(n, m, a, b);
                int your_ans = your_code(n, m, a, b);

                if (brute_ans != your_ans) {
                    cout << "Mismatch found!\n";
                    cout << "n=" << n << " m=" << m << "\n";
                    for (int i = 0; i < n; ++i) cout << a[i] << " " << b[i] << "\n";
                    cout << "Brute = " << brute_ans << ", Your = " << your_ans << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No mismatch found up to m=10!\n";
    return 0;
}
