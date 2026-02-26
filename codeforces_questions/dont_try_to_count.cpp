#include <iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false); // turn off sync with stdio
	cin.tie(nullptr);            // untie cin from cout
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		string x, s;
		cin >> x >> s;
		bool flag = 1;
		for (int i = 0; i <= 6; i++) {
			/*method to find if s  string is a substring of x*/
			if (x.find(s) != string::npos) {
				cout << i << endl;
				flag = 0;
				break;
			}
			x = x + x; n *= 2;
		}
		if (flag) {
			cout << -1 << endl;
		}
	}



}