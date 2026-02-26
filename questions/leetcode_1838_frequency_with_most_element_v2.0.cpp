/*
v.2.0 Optimised version
This code is accepted on leetcode
2025
ALL RIGHTS RESERVED
core logic and idea by MADHAV KOHLI
SLIDING WINDOW
Taught by coding sir
*/


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxFrequency(vector<int>& v, int k) {
	int x = k;
	int maxi = 1;
	sort(v.begin(), v.end());
	int s = 0, e = 0, d = 0;
	for ( e = 0; e < v.size() - 1; e++) {
		d = e - s;
		while ((k < (long long)(v[e + 1] - v[e]) * (d + 1)) and s < v.size()) {
			// 	cout << e << " " << s << endl;
			if (e == s) {
				e++; s++;
				if (e == v.size() - 1) {
					return maxi;
				}
			}
			else {
				k += (v[e] - v[s]);
				s++;
				d = e - s;
				// cout << "hi";
			}
		}
		int ans = e + 2 - s;
		maxi = max(maxi, ans);
		k -= (v[e + 1] - v[e]) * (d + 1);
	}
	return maxi;
}
int main() {

	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << maxFrequency(v, k);

}