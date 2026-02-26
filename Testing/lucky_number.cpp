#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxi = *max_element(a, a + n);
	int frequency[maxi + 1] {0};
	for (int i = 0; i < n; i++) {
		frequency[a[i]]++;
	}
	for (int i = 0; i <= maxi; i++) {
		cout << frequency[i] << " ";
	}
	cout << endl;
	int maxi1 = *max_element(frequency, frequency + maxi + 1);
	// cout << maxi1 << endl;
	int frequency1[maxi1 + 1] {0};
	for (int i = 0; i <= maxi; i++) {

		frequency1[frequency[i]]++;

	}
	int count = 0;
	for (int i = 1; i <= maxi1; i++) {
		if (frequency1[i] == 1 or frequency[i] == 0) {
			count++;
		}
		// cout << frequency1[i] << " ";
	}
	cout << count << endl;
	if (count == maxi1 ) {
		cout << "True";
	}
	else {
		cout << "False";
	}


}
