#include <iostream>
#include<algorithm>
#include<string>
bool compare(int x, int y) {
	return (x > y);
}
using namespace std;
int main() {

	int a[] {3, 7, 7, 5, 2};
	sort(a, a + (sizeof(a) / sizeof(int)), compare);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		cout << a[i] << " ";
	}


}