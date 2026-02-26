#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		if (binary_search(a, a + n, k)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}



}