#include <iostream>
using namespace std;
int i = 0;
int main() {

	float a;
	cin >> a;
	cout << a << endl;
	int count = 0;
	float s = 0, e = 1;
	while (s <= e) {
		double mid = (s + e) / 2;
		if (a > mid) {
			s = mid;
		}
		else if (a < mid) {
			e = mid;
		}
		else if (a == mid) {
			cout << 1 << endl << count;
			return 0;
		}
		count++;
		if (count > 100) {
			cout << 0 << endl << count;
			return 0;
		}
	}
}