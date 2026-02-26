#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		cout << b + 2 * c + b + 1 << endl;
	}
	else if (b > a) {
		cout << a + 2 * c + a + 1 << endl;
	}
	else {
		cout << a + b + 2 * c << endl;
	}

}