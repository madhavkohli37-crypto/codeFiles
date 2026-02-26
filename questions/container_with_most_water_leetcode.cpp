#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n + 1] {0};
	int maxi = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (maxi < a[i]) {
			maxi = a[i];
		}
	}
	h
	int s = 0, e = maxi * maxi;
	while (s <= e) {
		int mid = (s + e) / 2;
	}

}