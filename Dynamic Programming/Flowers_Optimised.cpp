#include <iostream>
using namespace std;
#define int long long
const int MOD=1000000007;
const int N=100007;
int k;
int dp[N]{1};\
int prefix[N]{0};
void F() {
for(int i=1;i<N;i++) {
  if(i-k<0) {
    dp[i]=dp[i-1];
    continue;
  }
  dp[i]=((dp[i-1]%MOD+dp[i-k]%MOD))%MOD;
}
for(int i=1;i<N;i++) {
  prefix[i]=(((prefix[i-1]%MOD)+(dp[i]%MOD))%MOD);
}
return;
int32_t main() {
  cout<<-6%10;
	int n;
	cin >> n >> k;
	F();
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout<<(((prefix[b])-(prefix[a-1])+MOD)%MOD)<<endl;
	}

}
