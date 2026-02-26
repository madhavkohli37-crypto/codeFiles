#include <iostream>
#include<string>
#include<algorithm>
// Need to include <iterator> for std::end if using C++11 or later, but often
// included with <algorithm> or C-style arrays work without it.
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int frequency[3] {0};
		for (int i = 0; i < k; i++) {
			if (s[i] == '0') {
				frequency[0]++;
			}
			else if (s[i] == '1') {
				frequency[1]++;
			}
			else {
				frequency[2]++;
			}
		}
		if (frequency[2] == k and k == n) {
			for (int i = 0; i < n; i++) {
				cout << "-";
			}
			cout << endl;
			continue;
		}
		else if (frequency[2] == k and k < n) {
			for (int i = 0; i < n; i++) {
				cout << "?";
			}
			cout << endl;
			continue;
		}
		char a[n];
		for (int i = 0; i < n; i++) {
			a[i] = '+';
		}

	}
}