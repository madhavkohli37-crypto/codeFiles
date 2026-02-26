#include <iostream>
#include<cstring>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (s.find("2026") != string::npos) {
			cout << 0 << endl;
		}
		else if (s.find("2025") == string::npos) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}

}