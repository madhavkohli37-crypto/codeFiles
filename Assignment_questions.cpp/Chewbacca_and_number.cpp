#include <iostream>
#include<string>
using namespace std;
int main() {

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 and s[i] == '9') {
			continue;
		}
		if (('0' + '9' - s[i]) < s[i] ) {
			s[i] = '0' + '9' - s[i] ;
		}
	}
	cout << s << endl;

}