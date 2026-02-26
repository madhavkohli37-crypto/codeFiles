#include <iostream>
using namespace std;
int main() {
	char n;
	int i = 1;
	char a[200005];
	while (cin.get(n)) {
		if (n == '\n') {
			break;
		}
		a[i] = n;
		i++;
	}
	i--;
	int m;
	cin >> m;
	cin.ignore();
	int count = 1;
	int prefix[i + 2] {0};
	int difference[i + 2] {0};
	int s[m + 1] {0};
	for (int j = 1; j <= m; j++) {
		cin >> s[j];
	}
	cin.ignore();
	for (int j = 1; j <= m; j++) {
		int f;
		f = s[j];
		if (count % 2 == 1) {
			difference[f] += 1;
		}
		else if (count % 2 == 0) {
			difference[f] -= 1;
		}
		count++;
	}
	prefix[1] = difference[1];
	for (int j = 1; j <= i / 2; j++) {
		prefix[j + 1] = prefix[j] + difference[j + 1];
	}
	for (int j = 1; j <= i / 2; j++) {
		// int f = s[j];
		if ((prefix[j] % 2) != 0) {
			char temp = a[j];
			a[j] = a[i - j + 1];
			a[i - j + 1] = temp;
		}
		// 	// cout << a[j] << endl;
	}
	for (int j = 1; j <= i; j++) {
		cout << a[j];
	}
	cin.get();
	return 0;
}