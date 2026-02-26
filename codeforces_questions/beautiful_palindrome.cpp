#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int x = a[n - 1], y = a[n - 2];
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] != x) {
				y = a[i];
				break;
			}
		}
		// cout << x << " " << y << endl;
		vector<int>ans;
		for (int i = 0; i < k; i++) {
			for (int i = 1; i <= n; i++) {
				if (i != x and i != y) {
					ans.push_back(i);
					y = x;
					x = i;
					break;
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";


	}

}