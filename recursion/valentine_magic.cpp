#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int n, m;
int ch[5001], ca[5001];
int min_sum(int b, int g) {
	if (b == n) {
		return 0;
	}
	if (g == m) {
		return INT_MAX;
	}
	int op1 = abs(ch[b] - ca[g]) + min_sum(b + 1, g + 1);
	int op2 = min_sum(b, g + 1);
	return min(op1, op2);
}
int32_t main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ch[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ca[i];
	}
	sort(ch, ch + n);
	sort(ca, ca + m);
	cout << min_sum(0, 0);


}