#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string x, string y) {
	string xy = x + y;
	string yx = y + x;
	return (xy > yx);
}
int main() {

	string a[100];
	int i = 0;
	while (cin >> a[i]) {
		i++;
	}
	// cout << i << endl;
	sort(a, a + i, compare);
	for (int j = 0; j < i; j++) {
		cout << a[j] ;
	}


}