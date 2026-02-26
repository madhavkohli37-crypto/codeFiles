#include <iostream>
using namespace std;
int main() {
	int k, c = 0;
	cin >> k;
	cin.ignore();
	char element[k] {};
	for (int i = 0; i < k; i++) {
		element[i] = (char)(97 + i);
	}
	char a[10000];
	char n;
	int frequency[k] {0};
	int i = 0;
	while (cin.get(n)) {
		if (n == '\n') {
			break;
		}
		a[i] = n;
		frequency[n - 97]++;
		i++;
	}
	for (int i = 0; i < k; i++) {
		if (frequency[i] == 0) {
			c++;
		}
	}
// 	cout<<c<<endl;
	char e_2[c];
	int l = 0;
	for (int i = 0; i < k; i++) {
		if (frequency[i] == 0) {
			e_2[l] = (char)(97 + i);
			// 	cout << e_2[l] << endl;
			l++;
		}
	}
// 	cout<<e_2[2]<<endl;
	// for (int i = 0; i < k; i++) {
	// 	cout << (char)(i + 97) << "-->" << frequency[i] << endl;
	// }
	// cout << a[i - 1] << endl;
	a[i] = '\0';
	i--;
	cout << i << endl;
	cout << a << endl;
	int s = 0, e = i, count = 0;
	while (s <= e) {
		if ((i + 1) % 2 == 1 and (((i + 1 + 1) / 2)) < k) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		else if ((i + 1) % 2 == 0 and ((i + 1) / 2) < k) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		if (a[s] != '?' and a[e] != '?' and a[s] != a[e]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		else if (a[s] != '?' and a[e] == '?') {
			a[e] = a[s];
		}
		else if (a[s] == '?' and a[e] != '?') {
			a[s] = a[e];
		}
		else if (a[s] == '?' and a[e] == '?') {
			count++;
		}
		s++; e--;
	}
	cout << count << endl << c << endl;
	int f = 0, g = i, m = 0;
// 	int flag=0;
	while (f <= g) {
		// int m = 0;
		if (a[f] == '?' and a[g] == '?') {
			if (count > c) {
				a[f] = 'a';
				a[g] = 'a';
				count--;
			}
			else if (count == c) {
				a[f] = e_2[m];
				a[g] = e_2[m];
				m++;
			}
		}
		// 		count--;
		// 		flag=1;
		// 	}
		// 	else if(count<c and flag==1) {
		// 	  a[f]=e_2[m];
		// 	  a[g]=e_2[m];
		// 	  count--;m++;
		// 	}
		else if (count < c) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		f++; g--;
	}


	cout << a;


}