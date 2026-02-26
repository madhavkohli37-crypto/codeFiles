#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int F(vector<int> c, int i ) {
	if (i >= c.size()) {
		return 0;
	}
	int op1 = c[i] + F(c, i + 1);
	int op2 = c[i] + F(c, i + 2);
	return min(op1, op2);
}
int minCostClimbingStairs(vector<int>& cost) {
	return min(F(cost, 0), F(cost, 1));
}
int main() {

	int n;
	cin >> n;
	vector<int>cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	cout << minCostClimbingStairs(cost);


}