#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			for (int k = 1; k <= i; k++) {
				cout << a[k + j] << " ";
			}
			cout << '\n';
		}
	}

}