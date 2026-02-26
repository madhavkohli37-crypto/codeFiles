#include <bits/stdc++.h>
using namespace std;
int factorial (int n) {
	int ans = 1;
	while (n) {
		ans *= n;
		n--;
	}
	return ans;
}
vector<int> v;
void re() {
	v.resize(100, 0);
	return;
}
bool flag = 0;
int j = 0;
int f = 0;
int op[100];
vector<int> p;
vector<vector<int>> ans;
void F(int t, int x, int l) {
	if (t == 0) {
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
		if (i > l and p[i] == p[i - 1]) {
			continue;
		}
		v[x] = p[i];
		x++;
		F(t - p[i], x, i);
		x--;
		if (flag) {
			flag = 0;
			return;
		}
	}
}
int combinationSum4(vector<int>& c, int t) {
	sort(c.begin(), c.end());
	re();
	p = c;
	F(t, 0, 0);
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < ans[i].size(); j++) {

		}
	}
	return f;
}
int main() {
	int n;
	cin >> n;
	vector<int>elements(n);
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	int t;
	cin >> t;
	cout << combinationSum4(elements, t);
}