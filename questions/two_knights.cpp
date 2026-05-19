#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000;
int dp[N]{0} ;
void initiate() {
    dp[0]=0;
    for(int k=1;k<=N;k++) {
        int x=k*k;
        dp[k]=(((x)*(x-1))/2)-4*(k-1)*(k-2);
    }
    return;
}
int32_t main() {
    int n;
    cin>>n;
    initiate();
    for(int i=1;i<=n;i++) {
        cout<<dp[i]<<endl;
    }
}
