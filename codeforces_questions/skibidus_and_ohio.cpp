#include <iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool flag = 1;
		string s;
		cin >> s;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == s[i + 1]) {
				cout << "1\n";
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << s.length() << endl;
		}
	}



}