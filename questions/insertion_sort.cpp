#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s = 1, e = 0;
	while (s < n) {
		int use = a[s];
		int i;
		for (i = e; i >= 0; i--) {
			if (use < a[i]) {
				a[i + 1] = a[i];
				// continue;
			}
			else if (use > a[i]) {
				a[i + 1] = use;
				break;
			}
		}
		// cout << i << endl;
		if (i < 0) {
			a[i + 1] = use;
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		e++;
		s++;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}