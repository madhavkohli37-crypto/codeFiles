#include <iostream>
#include<cmath>
using namespace std;
int facDigits(int n) {
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += log10(i);
	}
	ans++;
	return int(ans);
}
int main() {
	int n;
	cin >> n;
	cout << facDigits(n);

}