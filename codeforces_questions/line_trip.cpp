#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int s = a[0];
		int difference[n];
		for (int i = 0; i < n - 1; i++) {
			difference[i] = a[i + 1] - a[i];
		}
		difference[n - 1] = 2 * (x - a[n - 1]);
		sort(difference, difference + n );
		cout << max( s, difference[n - 1] ) << endl;
	}



}