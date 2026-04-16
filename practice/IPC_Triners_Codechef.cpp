#include<iostream>
#include<set>
#include<queue>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        set<int>days;
        int n, d;
        cin >> n >> d;
        priority_queue < pair < pair < int, int > , int >> pq;
        priority_queue < pair < pair < int, int > , int >> pq1;
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
        for(int i=1;i<=d;i++) {
            days.insert(i);
        }
       while(!pq.empty()) {
           if(days.lower_bound(-pq.top().first.second)==days.end()) {
               pq1.push(pq.top());
               pq.pop();
               continue;
           }
           set<int>::iterator start=days.lower_bound(-pq.top().first.second);
        set<int>::iterator end=start;
        int x=0;
        int g=pq.top().second;
        while(g--) {
            if(end==days.end()) {
                break;
            }
            x++;
           end = days.erase(end);
        }
        if(x<pq.top().second) {
            pair<pair<int,int>,int> p=pq.top();
            p.second-=x; 
            pq1.push(p);
        }
        pq.pop(); 
       }
       int ans=0;
       while( !pq1.empty()) {
           ans+=(pq1.top().first.first)*(pq1.top().second);
           pq1.pop();
       }
       cout<<ans<<endl;
    }
}
