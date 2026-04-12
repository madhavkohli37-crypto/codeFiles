#include <iostream>
#include<set>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int t;
   cin>>t;
   while(t--) {
       set<int>s1_x;
        multiset<int>s2_x;
        set<int>s1_y;
        multiset<int>s2_y;
       int n,m,q;
       int maxi;
    cin>>n>>m>>q;
    maxi=(n*m);
    s1_x.insert(0);
    s1_x.insert(n);
    s2_x.insert(n);
    s1_y.insert(0);
    s1_y.insert(m);
    s2_y.insert(m);
    while(q--) {
        int x,y;
        cin>>x>>y;
        if(!x) {
            if(s1_x.count(y)) {
                cout<<maxi<<"\n";
                continue;
            }
            auto ptr=(s1_x.upper_bound(y));
            int a=*ptr;
            int b=*(--ptr);
            multiset<int>::iterator it=s2_x.find(a-b);
            if(it!=s2_x.end()) {
                s2_x.erase(it);
            }
            s2_x.insert(a-y);
            s2_x.insert(y-b);
            s1_x.insert(y);
        }
        else {
             if(s1_y.count(y)) {
                cout<<maxi<<"\n";
                continue;
            }
            auto ptr=(s1_y.upper_bound(y));
            int a=*ptr;
            int b=*(--ptr);
            multiset<int>::iterator it=s2_y.find(a-b);
            if(it!=s2_y.end()) {
                s2_y.erase(it);
            }
            s2_y.insert(a-y);
            s2_y.insert(y-b);
            s1_y.insert(y);
        }
        int p=*(--s2_x.end());
        int j=*(--s2_y.end());
        int area=p*j;
        maxi=area;
        cout<<maxi<<"\n";
    }
   }
}
