#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		while (x > 1 and y > 1) {
			if (x > y) {
				x -= 2; y -= 1;
			}
			else if (y > x) {
				x -= 1; y -= 2;
			}
			else {
				x -= 2; y -= 1;
			}
		}
		if (x == 1 and y == 2) {
			cout << "YES\n";
		}
		else if (x == 2 and y == 1) {
			cout << "YES\n";
		}
		else if (x == 0 and y == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		// cout << x << " " << y;
		// cout << endl;
	}

}