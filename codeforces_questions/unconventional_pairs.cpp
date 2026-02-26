#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i, n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int maxi = INT_MIN;
		vector<int>difference;
		for (int i = 0; i < n; i++) {
			int d = a[i + 1] - a[i];
			difference.push_back(d);
			if (d > maxi) {
				maxi = d;
			}
			i++;
		}
		cout << maxi << endl;

	}

}