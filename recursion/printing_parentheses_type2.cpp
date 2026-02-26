/*in this type of variation we need to print all only those variations in which
there are exactly n openings and exactly n closings this is the exact question*/
#include <iostream>
using namespace std;
int n;
int x, y;
char op[100];
void F(int i, int x, int y) {
	if (i == 2 * n) {
		for (int j = 0; j < i; j++) {
			cout << op[j];
		}
		cout << endl;
		return;
	}
	if ( x > y) {
		op[i] = ')';
		// y++;
		F(i + 1, x, y + 1);
	}
	if (x < n) {
		op[i] = '(';
		// x++;
		F(i + 1, x + 1, y);
	}
	return ;
}
int main() {
	cin >> n;
	x = n; y = n;
	F(0, 0, 0);
}