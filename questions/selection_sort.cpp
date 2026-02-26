#include <iostream>
using namespace std;
int main()
/*relative ordering is maintained in selection sort*/{

	int n, count = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		// count++;
		int mini_i = j;
		for (int i = j; i < n ; i++) {
			// count++;
			if (a[mini_i] > a[i]) {
				mini_i = i;
			}
		}
		// cout << mini_i << " ";
		int temp = a[j];
		a[j] = a[mini_i];
		a[mini_i] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	// cout << endl << count;

}