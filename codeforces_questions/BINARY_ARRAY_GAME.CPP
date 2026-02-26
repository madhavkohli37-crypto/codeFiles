#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		bool a[n];
		int c_0 = 0, c_1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) {
				c_0++;
			}
			else if (a[i] == 1) {
				c_1++;
			}
		}
		if (c_0 == n) {
			cout << "BOB\n";
			continue;
		}
		else if (c_1 == n) {
			cout << "ALICE\n";
			continue;
		}
		else if (a[0]) {
			for (int i = 1; i < n; i++) {
				if (a[i] == 0) {
					cout << "ALICE\n";
					break;
				}
			}
			continue;
		}
		else if (a[n - 1]) {
			for (int i = 0; i < n - 1; i++) {
				if (a[i] == 0) {
					cout << "ALICE\n";
					break;
				}
			}
			continue;
		}
		else {
			cout << "BOB\n";
		}

	}



}