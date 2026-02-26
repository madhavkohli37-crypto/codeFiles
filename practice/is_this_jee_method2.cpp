// #define _USE_MATH_DEFINES
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define pi 3.1415926535
#define double float
int main() {

	int n;
	cin >> n;
	double a, b;
	double y;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		double s = 0, e = pi / 2;
		double ans = -1;
		int count = 0;
		while ((e - s) > 0) {
			double x = (s + e) / 2;
			double d;
			d = (sin(x) * ((2 * x) + a) - ((x * x) + (a * x) + (b)) * cos(x));
			cout << d << endl;
			if (d < 0) {
				ans = s;
				s = x;
			}
			else if (d > 0) {
				ans = e;
				e = x;
			}
			else if (d == 0) {
				ans = x;
				y = ((ans * ans) + (a * ans) + b) / sin(ans);
				break;
			}
			count++;

			y = ((ans * ans) + (a * ans) + b) / sin(ans);

		}
		cout << fixed << setprecision(10) << y << endl;
	}


}