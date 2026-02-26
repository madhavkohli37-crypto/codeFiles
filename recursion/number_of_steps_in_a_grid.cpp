#include <iostream>
using namespace std;
int n, m;
int F(int x, int y) {
	if (x + 1 == 0 and y + 1 == 0) {
		return 0;
	}
	else if (x + 1 == 0 or y + 1 == 0) {
		return 1;
	}
	if (x - 1 == 0 or y - 1 == 0) {
		return 1;
	}
	int ans = F(x - 1, y) + F(x, y - 1);
	return ans;
}
int main() {

	cin >> n >> m;
	cout << F(n, m);

}