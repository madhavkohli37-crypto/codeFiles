#include <iostream>
#include<string>
using namespace std;
string s;
char op[100];
void F(int i, int j) {
	if (i == s.length()) {
		op[j] = '\0';
		cout << op << endl;
		return;
	}
	op[j] = s[i];
	F(i + 1, j + 1);
	F(i + 1, j);
	return;
}
int main() {
	cin >> s;
	F(0, 0);


}