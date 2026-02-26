#include <iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int frequency[8] {0} ;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '4') {
			frequency[4]++;
		}
		else if (s[i] == '7') {
			frequency[7]++;
		}
	}
	if (frequency[4] == 0 and frequency[7] == 0) {
		cout << "NO\n";
	}
	else if ((frequency[4] + frequency[7]) == 4) {
		cout << "YES\n";
	}
	else if ((frequency[4] + frequency[7])  == 7) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}


}