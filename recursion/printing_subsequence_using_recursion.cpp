/*logic and designed by-Teachers
logical changes and editing by-Madhav Kohli
Executed by-Madhav Kohli
Code by-Madhav Kohli*/
// All Rights Reservd(C++ 17 )
// 2025
//Sublime Text
#include <iostream>
#include<string>
using namespace std;
string s;
int c = 1;
char ans[1005];
void F(int i, int j) {
	if (j == s.size()) {
		ans[i] = '\0';
		cout << c << ")" << ans << endl;
		c++;
		return;
	}
	F(i, j + 1);
	ans[i] = s[j];
	i++; j++;
	F(i, j);
	return;


}
int main() {


	cin >> s;
	F(0, 0);


}