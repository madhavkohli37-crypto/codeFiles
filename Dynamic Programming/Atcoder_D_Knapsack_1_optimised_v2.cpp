#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
int dp[100005][150];
vector<pair<int,int>>v;
int F(int w,int p) {
  if( p!=-1 and dp[w][p]!=-1) {
    return dp[w][p];
  }
  int op=0;
  int maxi=0;
  for(int i=p+1;i<v.size();i++) {
    if(w-v[i].first<0 and p!=-1) {
      dp[w][p]=maxi;
      return maxi;
    }
    int x=v[i].first,y=v[i].second;
    op=y+F(w-x,i);
    if(maxi<op) {
      maxi=op;
    }
  }
  if(p==-1) {
    return maxi;
  }
  dp[w][p]=maxi;
  return maxi;
} 
int32_t main() {
  int n,w;
  cin>>n>>w;
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
  }
  memset(dp,-1,sizeof(dp));
  sort(v.begin(),v.end());
  cout<<F(w,-1);
  
}
