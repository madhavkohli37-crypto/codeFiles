#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int c = 0, steps = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				c++;
			}
		}
		for (int i = 0; i < c; i++) {
			if (s[i] != '0') {
				steps++;
			}
		}
		cout << steps << endl;
	}


}