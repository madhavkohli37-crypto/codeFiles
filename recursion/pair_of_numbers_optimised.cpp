#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;
int min_steps = INT_MAX;
long long target;
void F(int x, int y, int count) {
	if (x == 1 and y == 1) {
		min_steps = min(count, min_steps);
		return;
	}
	if (y - x > 0) {
		F(x, y - x, count + 1);
	}
	else if (x - y > 0) {
		F(y, x - y, count + 1);
	}
}
void solve(int target) {
	for (int i = 1; i < target; i++) {
		F(i, target - i, 1);
	}
	return;
}
int main() {
	cin >> target;
	if (target == 1) {
		cout << "0\n";
		return 0;
	}
	solve(target);
	cout << min_steps << endl;


}