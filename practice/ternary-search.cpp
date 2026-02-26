#include <iostream>
#include<cmath>
#include<iomanip>
double F(double ans, double a, double b) {
	double y = ((ans * ans) + (a * ans) + b) / sin(ans);
	return y;
}
using namespace std;
#define pi 3.1415926535
#define float double
int main() {

	int n;
	cin >> n;
	double a, b;
	for (int i = 0; i < n; i++) {
		float ans = -1;
		cin >> a >> b;
		double s = 0, e = pi / 2;
		while ((e - s) > 1e-10) {
			float m1 = s + (e - s) / 3;
			float m2 = e - (e - s) / 3;
			if (F(m1, a, b) > F(m2, a, b)) {
				ans = m2;
				s = m1;
			}
			else if (F(m1, a, b) < F(m2, a, b)) {
				ans = m1;
				e = m2;
			}
			else {
				ans = m1;
				e = m2; s = m1;
			}
		}
		// cout << ans << endl;
		cout << fixed << setprecision(10) << F(ans, a, b) << endl;
	}
}