#include <iostream>
#include<string>
using namespace std;
int main() {

	int n;
	cin >> n;
	string x1 = "X++";
	string x2 = "++X";
	string y1 = "X--";
	string y2 = "--X";
	int plus {}, minus {};
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == x1 or s == x2) {
			plus++;
		}
		else if (s == y1 or s == y2) {
			minus++;
		}

	}
	cout << plus - minus;

}