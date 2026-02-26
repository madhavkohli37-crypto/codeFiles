#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int l[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}
	int d[n];
	for (int i = 0; i < n - 1; i++) {
		d[i] = l[i + 1] - l[i + 2];
		if (d[i] < 0) {
			d[i] = -d[i];
		}
		// cout << d[i] << " ";
	}

}