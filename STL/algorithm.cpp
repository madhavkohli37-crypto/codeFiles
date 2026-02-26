#include <iostream>
#include<algorithm>
// #include<string>
using namespace std;
#define endl '\n'
int main() {
	int a[] {1, 2, 3, 4, 5};
	sort(a, a + 6);
	cout << binary_search(a + 1, a + 4, 3) << endl;
	cout << lower_bound(a, a + 5, 3) - a << endl << upper_bound(a, a + 5, 3) - a << endl;
	cout << sizeof(a) / sizeof(int);




}