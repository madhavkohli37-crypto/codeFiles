#include <iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string a[10];
		int j = 0;
		while (cin >> a[j]) {
			j++;
			if (cin.get() == '\n') {
				break;
			}
		}
		for (int i = 0; i < j; i++) {
			cout << a[i].front();
		}
		cout << endl;

	}




}