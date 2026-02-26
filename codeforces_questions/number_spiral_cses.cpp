#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y and x % 2 == 0) {
			int ME = ((x * x) - (x) + 1);
			cout <<  ME + (x - y) << endl;
			// break;
		}
		else if (x > y and x % 2 == 1) {
			int ME = ((x * x) - (x) + 1);
			cout <<  ME - (x - y) << endl;
		}
		else if (y > x and y % 2 == 0) {
			int ME = ((y * y) - (y) + 1);
			cout << ME - (y - x) << endl;

		}
		else if (y > x and y % 2 == 1) {
			int ME = ((y * y) - (y) + 1);
			cout << ME + (y - x) << endl;
		}
		else {
			int ME = ((y * y) - (y) + 1);
			cout << ME - (y - x) << endl;
		}
	}

}