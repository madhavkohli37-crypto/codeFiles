#include <iostream>
#include<limits.h>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}

	int b[m + 1] {0};
	for (int i = 0; i < n; i++) {
		int element = a[i];
		b[element]++;
	}
	for (int i = 0; i <= m; i++) {
		// int element = a[i];
		if (b[i] > 0) {
			cout << i << "-->" << /*element << "-->" <<*/ b[i] << '\n';
		}
	}


}