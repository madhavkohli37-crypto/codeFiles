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
		string x, y;
		cin >> x >> y;
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if (x == y) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

}