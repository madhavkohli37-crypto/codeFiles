#include <bits/stdc++.h>
using namespace std;
int main() {
	int o = 0, e = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i += 2) {
		o += s[i] - '0';
	}
	for (int i = 1; i < s.size(); i += 2) {
		e += s[i] - '0';
	}
	if (s.size() % 2 == 0) {
		cout << e << endl << o << endl;
	}
	if (s.size() % 2 == 1) {
		cout << o << endl << e << endl;
	}


}