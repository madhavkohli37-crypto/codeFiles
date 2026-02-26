#include <iostream>
#include<algorithm>
#define int long long
int GCD(int x, int y) {
	int temp = 0;
	while (y != 0) {
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}
using namespace std;
int32_t main() {
	int x, y;
	cin >> x >> y;
	if (x > y) {
		swap(x, y);
	}
	int ans = (x * y) / GCD(y, x);
	cout << ans << endl;



}