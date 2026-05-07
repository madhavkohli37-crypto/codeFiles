#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
vector<pair<int,int>>v;
int F(int w) {
  int op=0;
  int maxi=0;
  for(int i=0;i<v.size();i++) {
    if(w-v[i].first<0) {
      return maxi;
    }
    int x=v[i].first,y=v[i].second;
    v.erase(v.begin()+i);
    op=y+F(w-x);
    if(maxi<op) {
      maxi=op;
    }
    v.insert(v.begin()+i,{x,y});
  }
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
  sort(v.begin(),v.end());
  cout<<F(w);
  
}
