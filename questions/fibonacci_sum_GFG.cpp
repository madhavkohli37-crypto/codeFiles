#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	long long f[100005];
	void fill() {
		f[0] = 0;
		f[1] = 1;
		for (int i = 0; i < 100005; i++) {
			if (i == 0 or i == 1) {
				continue;
			}
			f[i] = ( f[i - 1] + f[i - 2]) % 1000000007;
		}
	}
	long long int fibSum(long long int n) {
		fill();
		long long ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += (f[i]);
		}
		return ans % 1000000007 ;
	}
};
#define int long long
int32_t main() {
	Solution s;
	int n;
	cin >> n;
	cout << s.fibSum(n);
}