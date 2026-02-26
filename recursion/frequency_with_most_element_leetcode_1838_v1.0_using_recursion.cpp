/*
v.1.0 unoptimised but cleaner and faster
2025
ALL RIGHTS RESERVED
core logic and idea by MADHAV KOHLI
RECURSION
Taught by coding sir

*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxFrequency(vector<int>& v, int k) {
	if (v.size() == 1) {
		return 1;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<int>difference;
	for (int i = 1; i < v.size(); i++) {
		difference.push_back(v[0] - v[i]);
	}
	vector<int>prefix(difference.size());
	prefix[0] = difference[0];
	for (int i = 1; i < difference.size(); i++) {
		prefix[i] = prefix[i - 1] + difference[i];
	}
	int ans = (upper_bound(prefix.begin(), prefix.end(), k) - prefix.begin()) + 1;
	// if (ans > prefix.size()) {
	// 	ans--;
	// }
	v.erase(v.begin());
	return max(ans, maxFrequency(v, k));


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