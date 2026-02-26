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
		int mini = *min_element(a, a + n);
		if (maxi == mini) {
			cout << "YES\n";
			continue;
		}
		int frequency[maxi + 1] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i]]++;
		}
		int m = max((frequency[maxi] - frequency[mini]), -(frequency[maxi] - frequency[mini]));
		if (frequency[mini] + frequency[maxi] == n and m == 1) {
			cout << "YES\n";
		}
		else if (frequency[mini] + frequency[maxi] == n and m == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

}