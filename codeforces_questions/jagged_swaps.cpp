#include <iostream>
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
		if (a[0] == 1) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}

}