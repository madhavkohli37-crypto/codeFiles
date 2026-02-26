#include <iostream>
#include<climits>
using namespace std;
#define int long long
int32_t main() {

	int n, t;
	cin >> n >> t;
	int k[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	int min_t = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (k[i] < min_t) {
			min_t = k[i];
		}
	}
	// cout << min_t;
	int ans = -1;
	int s = 1, e = t * min_t;
	while (s <= e) {
		int mid = (s + e) / 2;
		int products = 0;
		for (int i = 1; i <= n; i++) {
			products += (mid / k[i]);
		}
		if (products >= t) {
			ans = mid;
			e = (mid - 1);
		}
		else {
			s = (mid + 1);
		}
	}
	cout << ans;
}

