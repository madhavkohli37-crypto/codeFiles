/*#C++17 ALL RIGHTS RESERVED//
sublime text 2025
logical implementation by MADHAV KOHLI
INITIAL LOGIC (v.1.0) BY MADHAV KOHLI
shortened optimised version can be thought and slight idea recommended by
BHOOMI KOHLI
shortened optimised version (v.2.0) thought by MADHAV KOHLI
shortened optimised version(v.2.0) logic by MADHAV KOHLI
shortened optimised version(v.2.0) designed and implemented by MADHAV KOHLI
//FINAL CODE EXECUTED BY MADHAV KOHLI//
*/
#include <iostream>
#include <string>
using namespace std;
string s;
string map[10] { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
char op[100] {'\0'};
void F(int i) {
	if (i == s.length()) {
		for (int j = 0; j < s.length(); j++) {
			cout << op[j];
		}
		cout << endl;
		return;
	}

	for (int j = 0; j < map[s[i] - 48].length(); j++) {
		op[i] = map[s[i] - 48][j];
		F(i + 1);
	}
	return;
}
int main() {

	cin >> s;
	F(0);

}