#include <iostream>
#include<cmath>
using namespace std;
#define int long long
int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, d;
		cin >> a >> b;
		c = a; d = b;
		int ans1 = 0;
		//Assuming we are taking the white chocolate first
		for (int i = 0; i < 50;) {

			a -= pow(2, i); i++;
			if (a >= 0) {
				ans1++;
			}
			else {
				break;
			}
			b -= pow(2, i); i++;
			if (b >= 0) {
				ans1++;
			}
			else {
				break;
			}
		}
		int ans2 = 0;
		//Assuming we are taking the dark chocolate first
		for (int i = 0; i < 50;) {

			d -= pow(2, i); i++;
			if (d >= 0) {
				ans2++;
			}
			else {
				break;
			}
			c -= pow(2, i); i++;
			if (c >= 0) {
				ans2++;
			}
			else {
				break;
			}
		}
		cout << max(ans1, ans2) << endl;
	}
}