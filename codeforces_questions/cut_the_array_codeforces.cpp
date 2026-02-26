#include <iostream>
using namespace std;
#define y i
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n + 1] {0};
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int prefix[n + 1] {0};
		// prefix[1]=a[1];
		for (int i = 1; i < n + 1; i++) {
			prefix[i] += (prefix[i - 1] + a[i]);
			// 	cout << prefix[i] << endl;
		}
		int x = a[1] % 3;
		for (int i = 2; i < n; i++) {
			if (x == 2) {
				if ((prefix[i] - prefix[1]) % 3 == 1 and (prefix[n] - prefix[i]) % 3 == 0) {
					cout << 1 << " " << y << endl;
					break;
				}
				else if ((prefix[i] - prefix[1]) % 3 == 0 and (prefix[n] - prefix[i]) % 3 == 1) {
					cout << 1 << " " << y << endl;
					break;
				}
				else if ((prefix[i] - prefix[1]) % 3 == 2 and (prefix[n] - prefix[i]) % 3 == 2) {
					cout << 1 << " " << y << endl;
					break;
				}
				else {
					cout << 0 << " " << 0 << endl;
					break;
				}

			}
			else if (x == 1) {
				if ((prefix[i] - prefix[1]) % 3 == 2 and (prefix[n] - prefix[i]) % 3 == 0) {
					cout << 1 << " " << y << endl;
					break;
				}
				else if ((prefix[i] - prefix[1]) % 3 == 0 and (prefix[n] - prefix[i]) % 3 == 2) {
					cout << 1 << " " << y << endl;
					break;
				}
				if ((prefix[i] - prefix[1]) % 3 == 1 and (prefix[n] - prefix[i]) % 3 == 1) {
					cout << 1 << " " << y << endl;
					break;
				}

				else {
					cout << 0 << " " << 0 << endl;
					break;
				}
			}
			else if (x == 0) {
				if ((prefix[i] - prefix[1]) % 3 == 2 and (prefix[n] - prefix[i]) % 3 == 1) {
					cout << 1 << " " << y << endl;
					break;
				}
				else if ((prefix[i] - prefix[1]) % 3 == 1 and (prefix[n] - prefix[i]) % 3 == 2) {
					cout << 1 << " " << y << endl;
					break;
				}
				else if ((prefix[i] - prefix[1]) % 3 == 0 and (prefix[n] - prefix[i]) % 3 == 0) {
					cout << 1 << " " << y << endl;
					break;
				}
				else {
					cout << 0 << " " << 0 << endl;
					break;
				}
			}
		}


	}

}