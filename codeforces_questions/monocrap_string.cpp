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
		int frequency[2] {0};
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				frequency[0]++;
			}
			else {
				frequency[1]++;
			}
		}
		// cout << abs(frequency[1] - frequency[0]) << endl;
		if (abs(frequency[1] - frequency[0]) == 0) {
			cout << "0\n";
			continue;
		}
		int d = abs(frequency[1] - frequency[0]), flag = 1;
		if (d == n) {
			cout << "-1\n";
			continue;
		}
		if (frequency[1] > frequency[0]) {
			int count = 0;
			int e = 0;
			while (e < n) {
				if (s[e] == 'b') {
					count++;
				}
				else {
					count = 0;
				}
				e++;
				if (count == d) {
					cout << d << endl;
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << "-1\n";
			}
		}
		else if (frequency[1] < frequency[0]) {
			int count = 0;
			int e = 0;
			while (e < n) {
				if (s[e] == 'a') {
					count++;
				}
				else {
					count = 0;
				}
				e++;
				if (count == d) {
					cout << d << endl;
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << "-1\n";
			}
		}


	}



}