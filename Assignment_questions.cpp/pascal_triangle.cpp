#include <iostream>
#include<vector>
using namespace std;
int main() {

	int n;
	cin >> n;
	vector<int>a[n];
	if (n == 1) {
		cout << " " << 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << "  " << 1 << endl << " " << 1 << " " << 1 << endl;
		return 0;
	}
	a[0] = {1};
	a[1] = {1, 1};
	for (int i = 2; i < n; i++) {
		a[i].resize(1000);
		for (int j = 0; j <= i; j++) {
			if (j == 0 or j == i) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}