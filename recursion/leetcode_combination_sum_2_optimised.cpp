/*
now since we have avoided making the duplicate ans
so we no longer need to check for duplicate vector in the ans
so we can remove the duplicate checking and erase condition

THIS VERSION IS ACCEPTABLE ON LEETCODE
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void re() {
	v.resize(50, 0);
	return;
}
bool flag = 0;
int f = 0;
vector<int> p;
vector<vector<int>> ans;

void F(int t, int x, int l) {
	if (t == 0) {
		v.resize(x);
		ans.push_back(v);
		v.resize(50, 0);
		flag = 1;
		f++;
		return;
	}
	if (t < 0) {
		flag = 1;
		return;
	}

	for (int i = l; i < p.size(); i++) {
		if (i > l and p[i] == p[i - 1]) {
			continue;
		}
		v[x] = p[i];
		x++;
		F(t - p[i], x, i + 1);
		x--;
		if (flag) {
			flag = 0;//backtracking
			return;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& c, int t) {
	sort(c.begin(), c.end());
	re();
	p = c;
	F(t, 0, 0);
	return ans;
}
int main() {
	vector<int>c;
	int n;
	cin >> n;
	int t;
	cin >> t;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		c.push_back(x);
	}
	vector<vector<int>>s;
	s = combinationSum2(c, t);
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

}