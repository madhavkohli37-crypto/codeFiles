#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<utility>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int ans=0;
        int n,d;
        cin>>n>>d;
        priority_queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<n;i++) {
            int x,y,z;
            cin>>x>>y>>z;
            pq.push({{-x,z},y});
        }
        int i=1;
        while(d>0) {
            if( -pq.top().first.first>i) {
               i++;
               d--;
           }
          else if( -pq.top().first.first <=d ) {
               d-=pq.top().second;
               i+=pq.top().second;
               pq.pop();
           }
           else {
               pair<pair<int,int>,int>p=pq.top();
                 p.second-=d;
                 pq.pop();
                 pq.push(p);
                break;
           }
        }
        while(!pq.empty()) {
           ans+=((pq.top().first.second)*(pq.top().second));
            pq.pop();
        }
        cout<<ans<<endl;
    }
}
