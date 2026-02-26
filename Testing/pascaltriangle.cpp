#include <iostream>
using namespace std;
int main() {

	int a, b;
	cin >> a >> b;
	int c = (a % b), r;
	while (c > 0) {
		r = b % c;
		b = c;
		c = b % r;
	}
	cout << r;


}