#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	int n, moves = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		while (a[i] > a[i + 1]) {
			a[i + 1]++;
			moves++;
		}
	}
	cout << moves;


}