/*
in this solution we are storing unnecessary solutions
becuse once we have solved for 1 elelement we do not need
to solve for it again
consider the example
1 1 2 5 6 7 10
once we get all the possible solutions for 1 and store it
in the vector ans we do not need to again explore all
the paths for the other 1 again becaus all the possible
paths are alredy explored with initial 1 in the code
so we need to ensure that if the we get 1 again anytime
later we need to skip it to avoid computuations
apart from the computations we also store all the unnecessary
duplicate solutions in the ans vector although we erase them later
but before reacing the point we would have erased them
the memory limit would have reahed due to large
ammount of unneceaasry duplicate vector stored in the ans

THIS VERSION IS NOT ACCEPTABLE ON LEETCODE

*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
void re() {
	v.resize(100, 0);
	return;
}
bool flag = 0;
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
	for (int i = 0; i < ans.size(); i++) {
		int j = i + 1;
		while (j < ans.size()) {
			if (ans[i] == ans[j]) {
				ans.erase(ans.begin() + j);
			} else {
				j++;
			}
		}
	}
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