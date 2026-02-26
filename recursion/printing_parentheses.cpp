/*in this type of variation we just need to print all the combinations possible*/
#include <iostream>
using namespace std;
int n, c = 1;
char op[1000];
void F(int i) {
	if (i == 2 * n) {
		cout << c << "." ;
		for (int j = 0; j < i; j++) {
			cout << op[j];
		}
		cout << endl;
		c++;
		return;
	}
	op[i] = '(';
	F(i + 1);
	op[i] = ')';
	F(i + 1);
	return;


}
int main() {
	cin >> n;
	F(0);

}