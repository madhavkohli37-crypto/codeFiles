#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int n, x, count = 0;
	cin >> n >> x;
	int a[n + 1] { -1};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int s = 1, sum = a[s];
	for (int e = 2; e <= n; e++) {
		sum += a[e];
		while (sum > x) {
			sum -= a[s];
			s++;
		}
		if (sum == x) {
			count++;
		}
	}
	if (a[1] == x) {
		count++;
	}
	cout << count;



}