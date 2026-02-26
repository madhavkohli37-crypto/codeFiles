#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {

		int maxi_i = 0;
		for (int i = 0; i < n - j; i++) {
			if (a[maxi_i] < a[i]) {
				maxi_i = i;
			}
		}
		cout << maxi_i << endl;
		int temp = a[n - 1 - j];
		a[n - 1 - j] = a[maxi_i];
		a[maxi_i] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}