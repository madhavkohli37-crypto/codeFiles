#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
int dp[3001][3001];
class Solution {
public:
    string x;
    string y;
    int l_a;
    int l_b;
    int lcs(int a, int b) {
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        if (a >= l_a or b >= l_b) {
            return dp[a][b] = 0;
        }
        if (x[a] == y[b]) {
            return dp[a][b] = 1 + lcs(a + 1, b + 1);
        } else {
            int op1 = lcs(a + 1, b);
            int op2 = lcs(a, b + 1);
            return dp[a][b] = max(op1, op2);
        }
    }
    int longestCommonSubsequence(string a, string b) {
        memset(dp, -1, sizeof(dp));
        l_a = a.length();
        l_b = b.length();
        x = a;
        y = b;
        return lcs(0, 0);
    }
};
int32_t main() {
  string a,b;
  cin>>a>>b;
  Solution s;
  int x=s.longestCommonSubsequence(a,b);
  int i=0,j=0;
  string ans;
  while(i<s.l_a and j<s.l_b) {
    if(a[i]==b[j]) {
        ans+=a[i];
        i++;
        j++;
    }
    else if(dp[i+1][j]>dp[i][j+1]) {
        i++;
    }
    else{
        j++;
    }
  }
  cout<<ans<<endl;
}
