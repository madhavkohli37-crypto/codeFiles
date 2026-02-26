#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int p, k, count = 0;
		cin >> p >> k;
		while (p <= n) {
			p = p + a[p] + k;
			count++;
		}
		cout << count << endl;
	}

}