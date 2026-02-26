#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int a, b;
	cin >> a >> b;
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	int c = 0;
	int d = b;
	while (true) {
		if (b < a) {
			b += d;
			c++;
		}
		if (c > 231) {
			cout << 230;
			return 0;
		}
		if (b > a) {
			break;
		}
	}
	cout << c;
}
