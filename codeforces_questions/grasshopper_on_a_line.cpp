#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, k;
		cin >> x >> k;
		if (x % k == 0) {
			cout << "2\n";
			cout << "1 " << x - 1 << endl;
		}
		else {
			cout << "1\n";
			cout <<  x << endl;
		}
	}

}