#include<iostream>

#include<vector>

#include<map>

#include<set>

#include<queue>

#include<utility>

#include<algorithm>

using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n, d;
        cin >> n >> d;
        priority_queue < pair < pair < int, int > , int >> pq;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            pq.push({
                {
                    z,
                    -x
                },
                y
            });
        }
        int i = 0;
        while (i < d) {
            int available_days;
            if (i >= -pq.top().first.second) {
                available_days = (d - i);
            }
            else {
                available_days = (d + pq.top().first.second + 1);
            }
            //    cout<<available_days<<endl;
            if (available_days >= pq.top().second) {
                i += pq.top().second;
                pq.pop();
            }
            else {
                pair < pair < int, int > , int > p = pq.top();
                p.second = abs(available_days - pq.top().second);
                pq.pop();
                pq.push(p);
                break;
            }
        }
        while (!pq.empty()) {
            ans += ((pq.top().first.first) * (pq.top().second));
            pq.pop();
        }
        cout << ans << endl;
    }
}
