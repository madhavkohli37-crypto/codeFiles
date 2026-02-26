#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i >= 3 && a[i - 2] > a[i - 1] && a[i - 1] > a[i])
                pref[i] = pref[i - 1] + 1;
            else
                pref[i] = pref[i - 1];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (r - l + 1 < 3) {
                cout << "YES\n";
            } else {
                // triples starting positions in [l, r-2] correspond to pref indices [l+2 .. r]
                int cnt = pref[r] - pref[l + 1];
                if (cnt > 0) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}

