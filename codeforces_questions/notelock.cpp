#include <iostream>
#include<string>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int count = 0;
		if (s[0] == '1') {
			count++;
		}
		for (int i = 1; i < s.size(); i++) {
			int c = 0;
			if (s[i] == '1') {
				if (i - k <= 0) {
					count++;
					continue;
				}
				for (int j = i - 1; s[j] == '0'; j--) {
					c++;
					if (c == count) {
						count++;
						break;
					}
				}
			}
		}
		cout << count << endl;
	}

}