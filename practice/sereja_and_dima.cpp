/*This is done using two pointer method
we have taken two pointers one at the starting and other
at the ending	(s and e)
*/
#include <iostream>
using namespace std;
int flag = -1;
int main() {

	int n;
	cin >> n;
	int a[n + 1] { -9};
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		// cout << a[i] << " ";
	}
	int sc = 0, ds = 0;
	int i = 1;
	int s = 1, e = n;
// 	int f=0;
	while (s < e) {
		// f++;
		if (a[s] > a[e]) {
			sc += a[s];
			sum -= a[s];
			s++;
			if (a[s] > a[e]) {
				ds += a[s];
				sum -= a[s];
				s++;
			}
			else {
				ds += a[e];
				sum -= a[e];
				e--;
			}
		}
		else {
			sc += a[e];
			sum -= a[e];
			e--;
			if (a[s] > a[e]) {
				ds += a[s];
				sum -= a[s];
				s++;
			}
			else {
				ds += a[e];
				sum -= a[e];
				e--;
			}
		}
	}
	// cout<<sum<<endl;
	if (n % 2 == 1) {
		sc += sum;
	}


	cout << sc << " " << ds;
}