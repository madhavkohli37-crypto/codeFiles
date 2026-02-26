#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2) {
		cout << " "1 << endl;
		cout << 1 << " " << 1 << endl;
	}
	else if (n >= 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = n - i; j > 0; j--) {
				cout << " ";
			}
			cout << 1;
			cout << '\n';
		}


	}