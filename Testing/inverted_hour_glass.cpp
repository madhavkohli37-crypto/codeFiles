#include <iostream>
using namespace std;
int main() {

	int n, i = 0, p;
	cin >> n;
	p = 4 * n;
	while (i <= n) {
		for (int j = n; j >= n - i; j--) {
			cout << j << " ";
		}
		for (int i = 1; i <= p - 2; i++) {
			cout << " ";
		}
		p -= 4;
		for (int j = n - i; j <= n; j++) {
			if (j == 0)
				continue;
			cout << j << " ";
		}
		i++;
		cout << '\n';
	}
	i--;
	p = 4;
	while (i >= 0) {
		for (int j = n; j > n - i; j--) {
			cout << j << " ";
		}
		for (int j = 1; j <= p - 2; j++) {
			cout << " ";
		}
		p += 4;
		for (int j = n - i; j <= n; j++) {
			if (j == n - i)
			{continue;}
			cout << j << " ";
		}
		i--;
		cout << '\n';
	}
}


