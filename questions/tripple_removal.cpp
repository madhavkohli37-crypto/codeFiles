#include <iostream>
#include<algorithm>
using namespace std;
#define int long ong
int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, q;
		cin >> n >> q;
		int a[n + 1] {0} ;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int l[q], r[q];
		for (int i = 0; i < q; i++) {
			cin >> l[i] >> r[i];
		}
		if (n % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		int frequency[2] {0};
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				frequency[0]++;
			}
			else {
				frequency[1]++;
			}
		}
		for (int i = 0; i < q; i++) {
			if (((abs(l[i] - r[i]) + 1) % 3) != 0) {
				cout << "-1\n";
				continue;
			}
			if (frequency[1] % 3 != 0 or frequency[2] % 3 != 0) {
				cout << "-1\n";
				continue;
			}


		}

	}




}