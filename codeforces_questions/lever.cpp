#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int s = 0;
		for (int i = 0; i < n; i++) {
			int x = a[i] - b[i];
			if (x > 0) {
				s += x;
			}
		}
		cout << s + 1 << endl;

	}

}