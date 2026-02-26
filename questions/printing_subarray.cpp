#include <iostream>
using namespace std;
int main() {
	// n*n*n computations in worst case,hence not optimal
	int n;
	cin >> n;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int f = 1; f <= n; f++) {
		for (int i = 1; i <= n - f + 1 ; i++) {
			for (int j = f; j <= n - i + 1; j++) {
				cout << a[j] << " ";
			}
			cout << '\n';
		}
	}
}