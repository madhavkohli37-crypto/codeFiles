#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
void re() {
	v.resize(100, 0);
	return;
}
bool flag = 0;
int j = 0;
int f = 0;
int op[100];
vector<int>p;
vector<vector<int>>ans;
void F(int t, int x, int l) {
	if (t == 0) {
		v.resize(x);
		ans.push_back(v);
		v.resize(100, 0);
		flag = 1;
		f++;
		return;
	}
	if (t < 0)  {
		flag = 1;
		return;
	}
	for (int i = l; i < p.size(); i++) {
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
vector<vector<int>> combinationSum(vector<int>& c, int t) {
	sort(c.begin(), c.end());
	re();
	p = c;
	F(t, 0, 0);
	// 	ans.resize(f);
	// 	for (int i = 0; i < f; i++) {
	// 		for (int j = 0; j < 100; j++) {
	// 			if (ans[i][j] == 0) {
	// 				ans[i].resize(j);
	// 				break;
	// 			}
	// 		}
	// 	}
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
	s = combinationSum(c, t);
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

}