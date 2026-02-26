#include <iostream>
using namespace std;
int main() {

	int n, p, s = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		p = n - i;
		for (int j = 0; j < i; j++) {
			cout << "  ";
			s = j;
		}
		while (p >= 0) {
			cout << p << " ";
			p--;
		}
		p = n - i;
		for (int j = 1; j <= p; j++) {
			cout << j << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		p = i;
		for (int j = s; j >= i; j--) {
			cout << "  ";
		}
		while (p >= 0) {
			cout << p << " ";
			p--;
		}
		p = i;
		for (int j = 1; j <= p; j++) {
			cout << j << " ";
		}
		cout << '\n';
	}

}