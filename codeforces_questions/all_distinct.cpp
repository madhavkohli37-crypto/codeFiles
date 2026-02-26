#include <iostream>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
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
		int count = 0;
		for (int i = 1; i <= maxi; i++) {
			if (frequency[i] % 2 == 1) {
				count++;
			}
		}
		int count1 = 0;
		for (int i = 1; i <= maxi; i++) {
			if (frequency[i] > 1 and frequency[i] % 2 == 0) {
				count1++;
			}
		}
		if (count1 % 2 == 1) {
			count1--;
		}
		count += count1;
		cout << count << endl;
	}

}