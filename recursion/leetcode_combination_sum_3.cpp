#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void re() {
	v.resize(100, 0);
	return;
}
bool flag = 0;
int j;
int f = 0;
vector<int> p{1, 2, 3, 4, 5, 6, 7, 8, 9} ;
vector<vector<int>> ans;
void F(int t, int x, int l) {
	if (t == 0 and x == j) {
		v.resize(x);
		ans.push_back(v);
		v.resize(100, 0);
		flag = 1;
		f++;
		return;
	}
	if (t < 0) {
		flag = 1;
		return;
	}
	for (int i = l; i < p.size(); i++) {
		v[x] = p[i];
		x++;
		F(t - p[i], x, i + 1);
		x--;
		if (flag) {
			flag = 0;
			return;
		}
	}
}
vector<vector<int>> combinationSum3(int k, int t) {
	j = k;
	re();
	F(t, 0, 0);
	return ans;
}
int main() {
	int k, n;
	cin >> k >> n;
	vector<vector<int>>s;
	s = combinationSum3(k, n);
	// cout << s[0][2];
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

}