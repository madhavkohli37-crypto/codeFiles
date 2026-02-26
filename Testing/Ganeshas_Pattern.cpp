#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n / 2; i++) {
		cout << "*";
		for (int i = 1; i < n / 2; i++) {
			cout << " ";
		}
		cout << "*";
		if (i == 1) {
			for (int i = 1; i <= n / 2; i++) {
				cout << "*";
			}
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		cout << "*";

	}
	cout << '\n';
	for (int i = 0; i <= n / 2; i++) {
		if (i + 1 == n / 2) {
			for (int i = 1; i <= n / 2; i++) {
				cout << "*";
			}
			continue;
		}
		for (int j = 1; j <= n / 2; j++) {
			if (i == n / 2) {
				continue;
			}
			cout << " ";
		}
		cout << "*";
		for (int i = 1; i < n / 2; i++) {
			cout << " ";
		}
		cout << "*";
		cout << '\n';
	}




}