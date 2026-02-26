#include <iostream>
#include<string>
using namespace std;
int main() {

	string a[4];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		cout << a[i][i] << endl;
	}
}