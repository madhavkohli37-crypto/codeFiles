#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n % 2 == 0) {
			for (int i = 0; i < (n - 1) / 2; i++) {
				cout << "-1 3 ";
			}
			cout << "-1 2" << endl;;
		}
		else {
			for (int i = 0; i < n / 2; i++) {
				cout << "-1 3 ";
			}
			cout << "-1" << endl;
		}
	}

}