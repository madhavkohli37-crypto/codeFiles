#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>r;//this is the given vector a
vector<int>m;//this is a possible permutation
void F(int i) {
	int x = 1;
	v.push_back(r);
	if (i == r.size()) {
		return;
	}


}
vector<vector<int>> permute(vector<int>& a) {
	// sort(a.begin(), a.end());
	r = a;
	F(0);
	return v;
}
int main() {
	vector<int>a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	vector<vector<int>>ans;
	ans = permute(a);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;


}