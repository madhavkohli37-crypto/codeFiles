#include <iostream>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int d1 = min(abs(a - b), abs(a - c));
		if (abs(b - c) > 1) {
			int l = (b + c) / 2;
			int d2 = max(abs(b - l), abs(c - l));
			if (d2 < d1) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else if (abs(b - c) == 1) {
			if (d1 > 1) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

}