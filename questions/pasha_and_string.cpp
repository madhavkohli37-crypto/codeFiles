#include <iostream>
using namespace std;
int main() {

	char a[200001];
	char n;
	int i = 1;
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
	for (int j = 0; j < m; j++) {
		int s;
		cin >> s;
		for (int j = s; j <= i / 2; j++) {
			char temp = a[j];
			a[j] = a[i - j + 1];
			a[i - j + 1] = temp;
		}
	}
	for (int j = 1; j <= i; j++) {
		cout << a[j];
	}
}
