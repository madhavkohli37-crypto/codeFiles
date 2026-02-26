#include <iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int frequency[2] {0};
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				frequency[0]++;
			}
		}
		bool flag = 0;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - i - 1]) {
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << frequency[0] << endl;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') {
					cout << i + 1 << " ";
				}
			}
		}
		else {
			cout << "0\n";
		}
		cout << endl;
	}



}