#include <iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {

	int n, x, f = 0;
	cin >> n >> x;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f += a[i];
	}
	sort(a+1, a + n+1);
	int s = 1, e = n, g = 0;
	while (s < e) {
		if (a[s] + a[e] <= x) {
			f -= (a[s] + a[e]);
			s++; e--; g++;
		}
		else {
			f -= a[e];
			e--; g++;
		}
	}
	if (f > 0) {
		g++;
	}
	cout << g;

}