#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		char a[n + 1] {'\0'};
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int m;
		cin >> m;
		char b[n + 1] {'\0'};
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		char c[m + 1] {'\0'};
		for (int i = 1; i <= m; i++) {
			cin >> c[i];
		}
		// cout << b[2] << endl;
		char dima[10];
		char vlad[10];
		int x = 0, y = 0;
		for (int i = 1; i <= m; i++) {
			if (c[i] == 'D') {
				dima[x] = b[i];
				x++;
			}
			else if (c[i] == 'V') {
				vlad[y] = b[i];
				y++;
			}
		}
		dima[x] = '\0'; vlad[y] = '\0';
		for (int i = y - 1; i >= 0; i--) {
			cout << vlad[i];
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << dima;
		cout << '\n';


	}


}