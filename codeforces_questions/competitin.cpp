#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int frequency[10000] {0};
	for (int i = 0; i < n; i++) {
		frequency[a[i]]++;
	}
	int target;
	cin >> target;
	if (frequency[target] == 0) {
		cout << "[-1,-1]";
	}
	else {
		cout << "[" << (lower_bound(a, a + n , target) - a)  << ",";
		cout << (upper_bound(a, a + n, target) - a) - 1 << "]";
	}



}