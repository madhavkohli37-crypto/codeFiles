/*
remember to optimise this code once you learn
DP(dynamic programming).
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
bool visited[20] {0} ;
long long F(vector<int> c, int i) {
	if (i == c.size()) {
		return 0;
	}
	if (i > c.size()) {
		return INT_MAX;
	}
	if (i < 0) {
		return INT_MAX;
	}
	visited[i] = 1;
	long long op1 = 1 + F(c, i + 1);
	long long op2;
	if (visited[i + c[i]] == 1) {
		op2 = INT_MAX;
	}
	else {
		op2 = 1 + F(c, i + c[i]);
	}
	visited[i] = 0;
	return min(op1, op2);

}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int>cost(n);
		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}
		visited[0] = 1;
		cout << F(cost, 0) << endl;
		memset(visited, 0, sizeof (visited));
	}


}