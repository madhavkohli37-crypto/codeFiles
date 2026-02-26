#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int h = pow(n + m, 0.5);
		if (h * h == (n + m) ) {
			if (h == 3) {
				cout << "YES\n";
				continue;
			}
			if (h % 2 == 0 and min(n, m) % 2 != 0) {
				cout << "NO\n";
				continue;
			}
			if (h > )
				cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

}