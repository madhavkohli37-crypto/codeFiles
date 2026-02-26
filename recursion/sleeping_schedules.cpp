#include <iostream>
using namespace std;
int n, h, l, r, maxi = 0;
int a[10000];
int max_sleep(int f, int t) {
	// one way :-
	// if (f == n) {
	// 	return 0;
	// }
	// other way :-
	if (f == n - 1) {
		int op1 = (t + a[n - 1]) % h;
		int op2 = (t + a[n - 1] - 1) % h;
		if (l <= op1 and r >= op1) {
			return 1;
		}
		if (l <= op2 and r >= op2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int op1 = (t + a[f]) % h;
	int op2 = (t + a[f] - 1) % h;
	if (op1 >= l and op1 <= r) {
		maxi = 1 + max(max_sleep(f + 1, op1), max_sleep(f + 1, op2));
	}
	else if (op2 >= l and op2 <= r) {
		maxi = 1 + max(max_sleep(f + 1, op1), max_sleep(f + 1, op2));
	}
	else {
		maxi = max(max_sleep(f + 1, op1), max_sleep(f + 1, op2));
	}
	return maxi;
}
int main() {

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << max_sleep(0, 0);

}