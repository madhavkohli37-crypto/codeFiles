#include <iostream>
using namespace std;
int main() {

	int n, m;
	cin >> n >> m;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l, r, d, difference[n + 1] {0};
	for (int i = 1; i <= m; i++) {
		cin >> l >> r >> d;
		difference[l] = difference[l] + d;
		difference[r + 1] = difference[r + 1] - d;
	}
	int prefix[n + 1] {0};
// 	prefix[1]=difference[1];
	for (int i = 2; i <= n; i++) {
		difference[i] += difference[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		a[i] += difference[i];
		cout << a[i] << " ";
	}


}