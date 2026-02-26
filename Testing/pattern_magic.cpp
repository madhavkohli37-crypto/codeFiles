#include <iostream>
using namespace std;
int main() {

	int n, k = 0, i;
	cin >> n;
	for ( i = 0; i < n; i++) {
		if (i == 0) {
			for (int i = 1; i < 2 * n; i++) {
				cout << "*";
			}
		}
		else {
			for (int j = 0; j < n - i; j++) {
				cout << "*";
			}
		}
		for (int j = i; j < k - 1; j++) {
			cout << " ";
		}
		for (int j = i; j < k; j++) {
			cout << " ";
		}
		for (int j = 0; j < n - i; j++) {
			if (i == 0) {
				continue;
			}
			cout << "*";
		}

		cout << '\n';
		k += 2;
	}
	k -= 2;
	i -= 2;
	for (int m = 1; m < n; m++) {
		if (m == n - 1) {
			for (int i = 1; i < 2 * n; i++) {
				cout << "*";
			}
		}
		else {
			for (int j = 0; j < n - i; j++) {
				cout << "*";
			}
		}
		for (int j = i + 2; j < k - 1; j++) {
			cout << " ";
		}
		for (int j = i + 2; j < k; j++) {
			cout << " ";
		}
		for (int j = 0; j < n - i; j++) {
			if (i == 0) {
				continue;
			}
			cout << "*";
		}

		cout << '\n';
		k -= 2;
		i--;
	}

}