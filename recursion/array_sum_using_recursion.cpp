#include <iostream>
using namespace std;
int n, sum = 0;
int a[10005];
int Array_sum(int p) {
	if (p == n - 1) {
		return sum + a[n - 1];
	}
	sum += a[p];
	Array_sum(p + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Array_sum(0) << endl;

}