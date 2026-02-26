#include <iostream>
using namespace std;
#define int long long
int k;
int F(int n) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	return F(n - 1) + F(n - k);
}
int32_t main() {
	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int ans = 0;
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			ans += F(i);
		}
		cout << ans << endl;
	}

}