#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			cout << " ";
		}
		if (i == 1 or i == n) {
			for (int j = 0; j < n; j++) {
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (int i = 1; i <= n - 2; i++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << '\n';


	}

}