#include <iostream>
#include<algorithm>
using namespace std;
int n;
char op[100] {'\0'};
void F(int i) {
	if (i == n) {
		for (int j = 0; j < i; j++) {
			cout << op[j];
		}
		cout << endl;
		return;
	}
	if (i == 0) {
		op[i] = 'a';
		F(i + 1);
		if (op[n - 1] == 'a' + n - 1) {
			return;
		}
	}
	for (int j = 0; j <= *(max_element(op, op + i)) - 96; j++) {
		op[i] = 'a' + j;
		F(1 + i);
		// cout << *(max_element(op, op + i)) - 96 << endl;
		// if (j == 1) {
		// 	break;
		// }
	}
	return;
}
int main() {
	cin >> n;
	F(0);
}