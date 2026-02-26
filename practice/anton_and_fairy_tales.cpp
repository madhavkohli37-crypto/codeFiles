/*This code is not accepted on codeforces because
overflow will occour in balance variable becuse range
of mid-m can be larger than 1e18 and hence long lomg
might also be not able to store its value.
otherwise all the test cases will be passed by the code*/
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
			int balance = (n - m - (((mid - m) * (mid - m)) + (mid - m)) / 2);
			if (balance <= 0) {
				ans = mid;
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}