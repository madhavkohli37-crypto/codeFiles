#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
map<pair<vector<pair<int,int>>,int>,int>dp;
int F(vector<pair<int,int>>v,int w) {
  if(dp.count({v,w})) {
    return dp[{v,w}];
  }
  int op=0;
  int maxi=0;
  for(int i=0;i<v.size();i++) {  
    if(w-v[i].first<0) {
      if(!dp.count({v,w})) {
        dp[{v,w}]=maxi;
      }
      return dp[{v,w}];
    }
    int x=v[i].first,y=v[i].second;
    v.erase(v.begin()+i);
    op=y+F(v,w-x);
    if(maxi<op) {
      maxi=op;
    }
    v.insert(v.begin()+i,{x,y});
  }
  if(!dp.count({v,w})) {
        dp[{v,w}]=maxi;
      }
  return maxi;
} 
int32_t main() {
  int n,w;
  cin>>n>>w;
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
  }
  sort(v.begin(),v.end());
  cout<<F(v,w);
  
}
