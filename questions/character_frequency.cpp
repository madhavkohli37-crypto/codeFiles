#include <iostream>
using namespace std;
int main() {

	int i = 0;
	char n;
	char a[1000];
	while (cin.get(n)) {
		if (n == '\n') {
			break;
		}
		a[i] = n;
		i++;
	}
	a[i] = '\0';
	i--;
	// cout << a;
	char maxi = '\0';
	for (int j = 0; j <= i; j++) {
		if (a[j] > maxi) {
			maxi = a[j];
		}

	}
	// cout << maxi << endl << int(maxi) << endl;
	int max = (int)maxi + 1;
	// cout << max;
	int frequency[257] {0};
	for (int j = 0; j <= i; j++) {
		char element = a[j];
		frequency[element]++;
		// cout << element << "-->" << frequency[element] << endl;
	}
	for (int j = 0; j <= 256; j++) {
		if (frequency[j] > 0) {
			char element = (char)j;
			cout << element << "-->" << frequency[j] << endl;
		}
	}


}