#include <iostream>
#include<limits.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] %= 10;
		}
		// long int m = INT_MIN;
		// for (int i = 0; i < n; i++) {
		// 	if (a[i] > m) {
		// 		m = a[i];
		// 	}
		// }
		// int element;
		int b[10] {0};
		for (int i = 0; i < n; i++) {
			int element = a[i];
			if (b[element] == 3) {
				continue;
			}
			b[element]++;
		}
		// if (b[element] > 3) {
		// 	b[element] = 3;
		// }
		int c[30] {0};
		int h = 0;
		for (int i = 0; i <= 9; i++) {
			// int element = a[i];
			if (b[i] > 0) {
				for (int j = 0; j < b[i]; j++, h++) {
					c[h] = i;
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < h; i++) {
			for (int j = i + 1; j < h; j++) {
				for (int l = j + 1; l < h; l++) {
					if ((c[i] + c[j] + c[l]) % 10 == 3) {
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag == 1) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}

}


