#include <bits/stdc++.h>
using namespace std;

static long long solve(int n, long long cLib, long long cRoad,
                       const vector<pair<int, int>> &edges)
{
    if (cLib <= cRoad)                  // cheaper to put a library in every city
        return (long long)n * cLib;

    vector<vector<int>> adj(n + 1);
    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<char> vis(n + 1, 0);
    long long total = 0;

    for (int s = 1; s <= n; ++s) {
        if (vis[s]) continue;

        int cmp = 0;                    // size of this component
        stack<int> st;
        st.push(s);
        vis[s] = 1;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            ++cmp;
            for (int v : adj[u])
                if (!vis[v]) { vis[v] = 1; st.push(v); }
        }
        // one library + (cmp-1) roads
        total += cLib + (cmp - 1) * cRoad;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        int n, m;
        long long cLib, cRoad;
        cin >> n >> m >> cLib >> cRoad;

        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        cout << solve(n, cLib, cRoad, edges) << '\n';
    }
    return 0;
}