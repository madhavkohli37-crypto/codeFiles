#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = n;
	int key;
	cin >> key;
	/*finding lower bound*/
	for (int s = 0, e = n - 1; s <= e;) {
		int mid = (s + e) / 2;
		if (a[mid] >= key) {
			ans = mid;
			e = mid - 1;
		}
		else if (a[mid] < key) {
			s = mid + 1;
		}

	}
	cout << ans << endl;
	/*finding upper bound*/
	int s = 0, e = n - 1;
	int ans_1 = n;
	int key_1;
	cin >> key_1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] > key_1) {
			ans_1 = mid;
			e = mid - 1;
		}
		else if (a[mid] <= key_1) {
			s = mid + 1;
		}

	}
	cout << key_1 << endl << ans_1;

}