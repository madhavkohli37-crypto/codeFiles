#include <iostream>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[N] {0};
int l[N], r[N], d[N];
int difference[N] {0};
int b[N] {0};


int32_t main() {

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}
	int x, y;

	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		difference[x]++;
		difference[y + 1]--;
	}
	for (int i = 2; i <= N; i++) {
		difference[i] = difference[i - 1] + difference[i];
	}
	for (int i = 1; i <= N; i++) {
		b[l[i]] += (d[i] * difference[i]);
		b[r[i] + 1] -= (d[i] * difference[i]);
	}
	for (int i = 2; i <= N; i++) {
		b[i] += b[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		a[i] += b[i];
		cout << a[i] << " ";
	}
}