#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<set>
#include<unordered_set>
using namespace std;
#define int long long
bool compare(int x,int y) {
    return (x>=y);
}
int32_t main() {
    int n,a,b,k,f;
    cin>>n>>a>>b>>k>>f;
    map<pair<string,string>,int>mp;
    string previous;
    for(int i=0;i<n;i++) {
        int cost=a;
        string s1,s2;
        cin>>s1>>s2;
        if(i and s1==previous) {
            cost=b;
        }
        previous=s2;
        string s=min(s1,s2);
        string x=max(s1,s2);
        s1=s;
        s2=x;
        pair<string,string> p=make_pair(s1,s2);
            mp[p]+=cost;
    }
    vector<int>c;
    for(pair<pair<string,string>,int> p:mp) {
        c.push_back(p.second);
    }
    int ans=0;
    sort(c.begin(),c.end(),compare);
    for(int i=0;i<c.size();i++) {
        if(f<c[i] and k) {
            ans+=f;
            k--;
        }
        else {
           ans+=c[i]; 
        }
    }
    cout<<ans<<endl;
}
