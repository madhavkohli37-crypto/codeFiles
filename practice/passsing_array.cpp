#include <iostream>
using namespace std;
#define int long long
/*we are passing arrays by reference/by address here
	hence we can see that we have sent the address of the first
	block only but the whole array is updated.
*/
int sum(int *a) {
	for (int i = 1; i <= 5; i++) {
		a[i] += 2;
	}
}
int32_t main() {

	int n;
	cin >> n;
	int a[6] {0};
	for (int i = 1; i <= 5; i++) {
		cin >> a[i];
	}
	sum(a);
	cout << a[2];


}