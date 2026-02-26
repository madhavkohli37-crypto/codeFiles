#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	for (int i = 1, k; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
			k = j;
		}
		int c = 2 + (n - i - 1) * 4;
		for (int j = 1; j <= c; j++) {
			cout << " ";
		}
		if (i == n) {
			for (int j = k - 1; j >= 1; j--) {
				cout << j << " ";
			}
			continue;
		}
		for (int j = k; j >= 1; j--) {
			cout << j << " ";
		}
		cout << '\n';
	}

}