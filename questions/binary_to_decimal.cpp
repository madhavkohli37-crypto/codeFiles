#include <iostream>
#include<string>
#include<cmath>
using namespace std;
#define int long long
int32_t main() {
	int n = 0;
	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			n += pow(2, (s.size() - 1 - i));
		}
	}
	cout << n << endl;

}