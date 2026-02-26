#include <iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int maxi = *(max_element(a, a + n));
		int size = 0;
		if (m > maxi) {
			size = m + 1;
		}
		else if (m <= maxi) {
			size = maxi + 1;
		}
		int frequency[size] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i]]++;
		}
		int steps = 0;
		for (int i = 0; i < m; i++) {
			if (frequency[i] == 0) {
				steps++;
			}
		}
		if (m > maxi) {
			cout << steps << endl;
			continue;
		}
		else if (m <= maxi) {
			if (steps >= frequency[m]) {
				cout << steps << endl;
			}
			else {
				cout << frequency[m] << endl;
			}
		}
		// cout << steps << endl;
	}



}