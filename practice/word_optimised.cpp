#include <iostream>
using namespace std;
int main() {

	int i = 0;
	char n;
	char a[102] {};
	while (cin.get(n)) {
		// if (n == '\n') {
		// 	break;
		// }
		a[i] = n;
		i++;
	}
	if (a[i - 1] == '\n') {
		a[i - 1] = '\0';
		i--;
	}
	else {
		a[i] = '\0';
	}

	// i--;
	// cout << i << endl;
	// cout << a;
	// cout << endl;
	int maxi = (int)'Z';
	// cout << maxi << endl;
	int count = 0;
	for (int j = 0; j < i; j++) {
		if ((int)a[j] <= maxi) {
			count++;
		}
	}
	// cout << count << endl;
	if (count > (i) / 2) {
		for (int j = 0; j < i; j++) {
			if ((int)a[j] > maxi) {
				a[j] -= 32;
			}
		}

	}
	else if (count <= (i) / 2) {
		for (int j = 0; j < i; j++) {
			if ((int)a[j] <= maxi) {
				a[j] += 32;
			}
		}

	}
	cout << a;
	return 0;


}