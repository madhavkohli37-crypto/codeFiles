#include <iostream>
#include<climits>
using namespace std;
int target;
int min_steps(int x, int y) {
	if ((x > target) or (y > target)) {
		return 1e8;
	}
	else if (x == target or y == target) {
		return 0;
	}
	else {
		return 1 + (min(min_steps(x + y, y), min_steps(x, x + y)));
	}
}
int main() {

	cin >> target;
	cout << min_steps(1, 1);

}