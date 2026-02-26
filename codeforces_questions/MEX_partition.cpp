#include <iostream>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int m = *max_element(a, a + n);
		int frequency[102] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i]]++;
		}
		int c = 0;
		for (int i = 0; i <= m; i++) {
			if (frequency[i] >= 1) {
				c++;
			}
		}
		if (c == m + 1) {
			cout << m + 1 << endl;
			continue;
		}
		if (frequency[0] == 0  ) {
			cout << "0\n";
			continue;
		}
		if (frequency[0] == 1) {
			for ( int i = 0; i <= m; i++) {
				if (frequency[i] == 0) {
					cout << i << endl;
					break;
				}
			}
			continue;
		}
		int count = 0;
		for (int i = 1; i <= m; i++) {
			if (frequency[0] == frequency[i]) {
				count++;
			}
			else {
				break;
			}
		}
		if (frequency[count + 1] == 0) {
			cout << count + 1 << endl;
		}
		else {
			for (int i = 0; i <= m; i++) {
				if (frequency[i] == 0) {
					cout << i << endl;
					break;
				}
			}
		}

	}

}