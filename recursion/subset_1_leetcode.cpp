#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>r;
vector<int>m;
void F(int i) {
	if (i == r.size()) {
		v.push_back(m);
		return;
	}
	m.push_back(r[i]);
	F(i + 1);
	m.pop_back();
	F(i + 1);
	return;
}
vector<vector<int>> subsets(vector<int>& a) {
	sort(a.begin(), a.end());
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
	ans = subsets(a);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;


}