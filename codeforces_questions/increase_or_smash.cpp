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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int maxi = *max_element(a, a + n);
		int frequency[maxi + 1] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i]]++;
		}
		int count = 0;
		for (int i = 0; i <= maxi; i++) {
			if (frequency[i] >= 1) {
				count++;
			}
		}
		// cout << count << endl;
		cout << (2 * (count - 1) + 1) << endl;
	}

}