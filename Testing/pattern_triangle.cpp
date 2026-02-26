#include <iostream>
using namespace std;
int main() {

	int n, j;
	cin >> n;
	for (int i = 1, p = i, m; i <= n; i++, p += 2) {
		for (int j = p; j <= 2 * (n - 1); j++) {
			cout << " ";
		}

		for (j = i; j <= (2 * i - 1); j++) {
			cout << j << "  ";
			m = j;
		}
		j--;
		while (m >= i) {
			if (m == j) {
				m--;
				continue;
			}
			cout << m << "  ";
			m--;
		}
		cout << '\n';
	}
}

