/*hint->
USE BINARY SEARCH TO SEARCH FOR ELEMENT INSTEAD OF FREQUENCY ARRAY
*/
#include <iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int total = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				total++;
			}
		}
		int steps = 0;
		if ((total % 2 == 0)) {
			steps += 0;
		}
		else if ((total % 2 == 1)) {
			steps += 1 - a[0];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				steps++;
			}
		}
		cout << steps << endl;
	}


}