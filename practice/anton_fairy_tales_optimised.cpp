#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int n, m;
	cin >> n >> m;
	if (n <= m) {
		cout << n;
		return 0;
	}
	int s = 1, e = n;
	int ans = 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		int balance;
		if (mid <= m) {
			s = mid + 1;
		}
		else if (mid > m) {
			long long k = mid - m;
			long long bound = n - m;        // positive, ≤ 9e18
			bool ok;

			if (k <= 5000000000LL) {
				// k(k+1)/2 fits in 64 bits
				ok = (k * (k + 1) / 2 >= bound);
			} else {
				// k(k+1)/2 already exceeds 9e18, so inequality holds
				ok = true;
			}

			if (ok) {
				ans = mid;
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}