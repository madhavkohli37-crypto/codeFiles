#include <iostream>
using namespace std;
#define int long long
int32_t main() {

	char n;
	int i = 0;
	char z[400];
	int frequency[256] {0};
	while (cin.get(n)) {
		if (n == '\n') {
			break;
		}
		z[i] = n;
		frequency[n]++;
		i++;
	}
	z[i] = '\0';
	// i--;
	// cout << z << endl << i << endl;
	// for (int j = 0; j < 256; j++) {
	// 	if (frequency[j] > 0) {
	// 		cout << (char)j << "-->" << frequency[j] << endl;
	// 	}
	// }
	// cout << frequency['B'];
	int b[3];
	for (int j = 0; j < 3; j++) {
		cin >> b[j];
	}

	int p[3];
	for (int j = 0; j < 3; j++) {
		cin >> p[j];
	}
	int r;
	cin >> r;
	int s = 0, e = 1e12 + 100;
	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;
		int PRB = (p[0] * ((mid * frequency['B']) - b[0]));
		if (PRB < 0) {
			PRB = 0;
		}
		int PRS = (p[1] * ((mid * frequency['S']) - b[1]));
		if (PRS < 0) {
			PRS = 0;
		}
		int PRC = (p[2] * ((mid * frequency['C']) - b[2]));
		if (PRC < 0) {
			PRC = 0;
		}
		int money = PRB + PRC + PRS;
		if (money <= r) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << endl;

}




