#include <iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int n = s.size();
		for (int i = 0; i < n - 2; i++) {
			cout << s[i];
		}
		cout << "i\n";



	}
}