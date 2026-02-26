#include <iostream>
#include<cmath>
using namespace std;
#define int long long
int ans[100000] {1} ;
void E() {
	for (int i = 1; i < 31; i++) {
		ans[i] = ans[i - 1] + pow(2, i);
	}
	return;
}
int Esum(int n) {
	return ans[n];
}
int32_t main() {
	E();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int A, B;
		cin >> A >> B;
		int a = min(A, B);
		int b = max(A, B);
		// cout << a << " " << b << endl;
		if (a == 1 and b == 1) {
			cout << 1 << endl;
		}
		else if (a < b) {
			bool flag = 0;
			while (a) {
				for (int i = 1; i < 30; i++) {
					if (((2 * a) + 1) == Esum(i)) {
						flag = 1;
						cout << i + 1 << endl;
						break;
					}
					if (((2 * a) + 1) < Esum(i)) {
						break;
					}
				}
				if (flag == 0) {
					a--;
				}
				else if (flag) {
					break;
				}
			}
		}
		else if (a == b) {
			a--;
			while (a) {
				bool flag = 0;
				for (int i = 1; i < 30; i++) {
					if (((2 * a) + 1) == Esum(i)) {
						flag = 1;
						cout << i + 1 << endl;
						break;
					}
					if (((2 * a) + 1) < Esum(i)) {
						break;
					}
				}
				if (flag == 0) {
					a--;
				}
				else if (flag) {
					break;
				}
			}
		}


	}
}