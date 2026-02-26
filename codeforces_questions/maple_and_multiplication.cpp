#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0\n";
		}
		else if (b % a == 0 or a % b == 0) {
			cout << "1\n";
		}
		else {
			cout << "2\n";
		}
	}

}