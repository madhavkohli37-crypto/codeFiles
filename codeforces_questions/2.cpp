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
		for (int i = 0; i < t; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 1; i < a[0]; i++) {
			if (a[0] % i != 0) {
				cout << i << endl;
				break;
			}
		}
	}


}