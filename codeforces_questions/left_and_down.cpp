#include <iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	while (b != 0) {
		long long x = a;
		a = b; b = x % b;
	}
	return a;
}
#define int long long
int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		int m = max(a, b), cost = 0;
		if (m <= k) {
			cout << "1\n";
			continue;
		}
		int mini = min(a, b);
		int num = gcd(m, mini);
		int x = m / num;
		if (num > 1 and x <= k ) {
			cout << "1\n";
			continue;
		}
		cout << "2\n";





	}
}