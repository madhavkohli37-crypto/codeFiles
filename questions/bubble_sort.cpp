#include <iostream>
using namespace std;
int main()
/*relative ordering is not maintained in bubble sort.*/ {

	int n, count = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		count++;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				count++;
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << count;


}