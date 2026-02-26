#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	vector<int>a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int n = a.size();
	// cout << n;
	if (n < 3) {
		cout << "[]" << endl;
	}
	else if (n == 3) {
		int sum = a[0] + a[1] + a[2];
		if (sum == 0) {
			cout << "[" << a[0] << "," << a[1] << "," << a[2] << "]" << endl;
		}
		else if (sum != 0) {
			cout << "[]";
		}
	}
	else if (n > 3) {
		int maxi = *max_element(a.begin(), a.end());
		int frequency[maxi + 1] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i]]++;
		}
		cout << "[";
		if (frequency[0] >= 3) {
			cout << "0,0,0";
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == a[i - 1] and i > 0 ) {
				continue;
			}
			for (int j = i + 1; j < n; j++) {
				if (a[j] == a[j + 1] ) {
					continue;
				}
				if (binary_search(a.begin() + j, a.end(), -(a[i] + a[j]))) {
					cout << a[i] << "," << a[j] << "," << -(a[i] + a[j]) << " ";
				}
			}
		}
		cout << "]\n";
	}
}

