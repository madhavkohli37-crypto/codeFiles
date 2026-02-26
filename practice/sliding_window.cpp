#include <iostream>
using namespace std;
int main() {

	int n, t;
	cin >> n >> t;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxi = -1;
	int s = 1, e = 1, tc = 0;
	int count = 0;
	for (int e = 1; e <= n; e++) {
		tc += a[e];
		count = (e - s) + 1;
		cout << tc << " ";
		if (tc > t) {
			count--;
			while (s <= e and tc > t) {
				tc -= a[s];
				s++;
			}
		}
		cout << count << endl;
		if (maxi < count) {
			maxi = count;
		}
	}
	cout << maxi;
}