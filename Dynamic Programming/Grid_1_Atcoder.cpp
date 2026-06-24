#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
const int MOD=1e9 + 7;
char grid[1000][1000];
int dp[1000][1000];
int32_t main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        if(grid[0][i]=='#') {
            for(int j=i;j<m;j++) {
                dp[0][j]=0;
            }
            break;
        }
        else {
            dp[0][i]=1;
        }
    }
    for(int i=0;i<n;i++) {
        if(grid[i][0]=='#') {
            for(int j=i;j<n;j++) {
                dp[j][0]=0;
            }
            break;
        }
        else {
            dp[i][0]=1;
        }
    } 
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(grid[i][j]=='#') {
                dp[i][j]=0;
            }
            else {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD ;
            }
        }
    }
    cout<<dp[n-1][m-1]%MOD<<endl;
}

   
