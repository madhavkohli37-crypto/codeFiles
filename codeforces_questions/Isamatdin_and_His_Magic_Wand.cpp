#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (a[0] % 2 == 0) {
			int j;
			for ( j = 1; j < n; j++) {
				if (a[j] % 2 == 1) {
					sort(a, a + n);
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
		else if (a[0] % 2 == 1) {
			int j;
			for ( j = 1; j < n; j++) {
				if (a[j] % 2 == 0) {
					sort(a, a + n);
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}


	}
}