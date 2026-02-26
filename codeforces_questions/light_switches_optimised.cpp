#include <iostream>
using namespace std;
char a[200000 + 5];
bool check(char*a, int n) {
	for (int i = 2; i < n - 2; i++) {
		if (a[i] == '0' and (a[i + 1] == '1' and a[i + 2]  == '1') and (a[i - 1]  == '1' and a[i - 2] == '1')) {
			return true;
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int frequency[2] {0};
		for (int i = 0; i < n; i++) {
			frequency[a[i] - '0']++;
		}
		int position_0[frequency[0]], position_1[frequency[1]];
		// cout << frequency[0] << endl << frequency[1];
		for (int i = 0, j = 0, k = 0; i < n; i++) {
			if (a[i] == '0') {
				position_0[j] = i;
				j++;
			}
			else {
				position_1[k] = i;
				k++;
			}
		}
		if (frequency[0] == 1 or frequency[0] == 0) {
			cout << "YES\n";
			continue;
		}
		if (frequency[0] == 2 and position_0[0] == 0 and position_0[frequency[0] - 1] == frequency[0]) {
			cout << "YES\n";
			continue;
		}
		if (position_0[0] != 0) {
			int i = 0, flag = 0;
			while (i < frequency[0] - 1) {
				if ((position_0[i + 1] - position_0[i]) > 2) {
					cout << "NO\n";
					flag = 1;
					break;
				}
				else {
					i += 2;
				}
			}
			if (flag == 1) {
				continue;
			}
			else if (position_0[i] == )
			}

		// cout << endl;
		// for (int i = 0; i < frequency[0]; i++) {
		// 	cout << position_0[i] << " ";
		// }
		// cout << endl;


	}
}
