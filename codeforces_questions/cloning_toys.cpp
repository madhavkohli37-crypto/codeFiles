#include <iostream>
using namespace std;
int main() {

	long long int x, y;
	cin >> x >> y;
	if (y == 1 and x != 0) {
		cout << "NO\n";
	}
	else if (x == 2 and y == 1) {
		cout << "NO\n";
	}
	else if (x == 0 and y == 1) {
		cout << "YES\n";
	}
	else if (y == 0) {
		cout << "NO\n";
	}
	else if (x + 1 < y) {
		cout << "NO\n";
	}
	else if (x == y) {
		cout << "NO\n";
	}
	else if ((y - x - 1) % 2 == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

}