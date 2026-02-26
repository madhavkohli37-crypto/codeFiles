#include <iostream>
using namespace std;
int main() {

	int n, t;
	cin >> n >> t;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// cout << a[1] << endl;
	int prefix[n + 1] {0};
	prefix[1] = a[1];
	// cout << prefix[1] << endl;
	for (int i = 2; i <= n; i++) {
		prefix[i] = a[i] + prefix[i - 1];
		// cout << prefix[i] << endl;
	}
	// cout << prefix[1] << endl;
	int count[n + 5] {0};
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		int f = t;
		if (t - a[i] >= 0) {
			count[i]++;
		}
		else {
			continue;
		}
		// cout << count[i] << endl;
		f -= a[i];
		// cout << f << endl;
		int s = i + 1, e = n;
		// cout << s << " " << e << endl;
		while (s <= e) {
			int mid = (e + s) / 2;
			// cout << mid << endl;
			if (f >= (prefix[mid] - prefix[i])) {
				ans = mid;
				s = mid + 1;
				flag = 1;
			}
			else {
				e = mid - 1;
			}
		}
		// cout << ans << endl;
		if (flag == 1) {
			ans -= i;
			// cout << ans << endl;
			count[i] += ans;
		}
		if (i == n) {
			count[i] = 1;
		}
		// cout << count[i] << endl;
	}
	int maxi = -2;
	for (int i = 1; i <= n; i++) {
		if (count[i] > maxi) {
			maxi = count[i];
		}
	}
	cout << maxi;


}