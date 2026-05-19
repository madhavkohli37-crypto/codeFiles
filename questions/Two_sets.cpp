#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>d;
vector<int> F(int s,int n) {
    vector<int>v;
    while(s>n) {
        v.push_back(n);
        d.pop_back();
        s-=n;
        n--;
    }
    auto x=find(d.begin(),d.end(),s);
    d.erase(x);
    v.push_back(s);
    return v;
}
int32_t main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        d.push_back(i);
    }
    int sum=(n*(n+1))/2;
    if(sum%2) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        vector<int>v=F(sum/2,n);
        cout<<v.size()<<endl;
        for(int x:v) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<d.size()<<endl;
        for(int x:d) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
