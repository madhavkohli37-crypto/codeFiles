#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n;
 int a[100005];
 int b[100005];
 int c[100005];
 int dp[100005][3];
int F(int i,int j) {
  if(i==n) {
    return 0;
  }
  if(i==0) {
  int op1=a[i]+F(i+1,1);
  int op2=b[i]+F(i+1,2);
  int op3=c[i]+F(i+1,3);
  return max({op1,op2,op3});
  }
  if(dp[i][j]!=-1) {
    return dp[i][j];
  }
  if(j==1) {
    int op1=b[i]+F(i+1,2);
    int op2=c[i]+F(i+1,3);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
  }
  else if(j==2) {
    int op1=a[i]+F(i+1,1);
    int op2=c[i]+F(i+1,3);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
  }
  else if(j==3) {
    int op1=b[i]+F(i+1,2);
    int op2=a[i]+F(i+1,1);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
  }
}
int32_t main() {
  cin>>n;
 
  for(int i=0;i<n;i++) {
    cin>>a[i]>>b[i]>>c[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<F(0,0);
}
