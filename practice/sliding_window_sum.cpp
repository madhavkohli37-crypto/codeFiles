#include <iostream>
#include<cmath>
#include<climit>
using namespace std;
#define int long long
int32_t main() {

	int n, k;
	cin >> n >> k;
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	int i[n + 1] {0};
	i[1] = x;
	// cout << i[1] << " ";
	for (int j = 2; j <= n; j++) {
		i[j] = (a * (i[j - 1]) + b) % c;
		// cout << i[j] << " ";
	}
	// cout << endl;
	int sum = 0, ans = INT_MIN;
	for (int e = 1; e <= k; e++) {
		sum += i[e];
	}
	ans = sum;
	// cout << sum << " ";
	for (int s = 2; s <= n + 1 - k; s++) {
		sum -= (i[s - 1]);
		sum += (i[s + k - 1]);
		// cout << sum << " ";
		ans = (sum xor ans);
	}
	// cout << endl;
	cout << ans;


}