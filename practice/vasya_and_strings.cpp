#include <iostream>
using namespace std;
int main() {

	int n, k, maxia = 0, maxib = 0;
	cin >> n >> k;
	char a[n + 1] {'\0'};
	char b[n + 1] {'\0'};
	int frequency['b' + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		if (a[i] == 'a') {
			frequency['a']++;
		}
		else {
			frequency['b']++;
		}
	}
	int min;
	// cout << frequency['a'] << " " << frequency['b'];
	if (frequency['a'] > frequency['b']) {
		min = frequency['b'];
	}
	else {
		min = frequency['a'];
	}
	if (min <= k) {
		cout << n;
	}
	else {
		int m = 0;
		/*Case 1 :-
		converting b-->a  :-
		*/
		int s = 1, e = 1;
		while (e <= n) {
			while (m < k or a[e] == 'a') {
				if (a[e] == 'b') {
					b[e] = 'a';
					m++;
				}
				e++;
			}
			// 	cout<<e<<endl;
			if (maxia < (e - s)) {
				maxia = e - s;
			}
			// 	cout<<maxi<<endl;
			if ((e - 1) == n) {
				break;
			}
			/*
			if i am here it means i
			am in an undesired window hence make it
			desired again
			*/
			while (m == k) {
				if (a[s] == 'b') {
					m--;
				}
				s++;
			}
			// e--;
		}
		m = 0;
		// int m = 0;
		/*Case 2 :-
		converting a-->b  :-
		*/
		s = 1, e = 1;
		while (e <= n) {
			while (m < k or a[e] == 'b') {
				if (a[e] == 'a') {
					b[e] = 'a';
					m++;
				}
				e++;
			}
			// 	cout<<e<<endl;
			if (maxib < (e - s)) {
				maxib = e - s;
			}
			// 	cout<<maxi<<endl;
			if ((e - 1) == n) {
				break;
			}
			/*
			if i am here it means i
			am in an undesired window hence make it
			desired again
			*/
			while (m == k) {
				if (a[s] == 'a') {
					m--;
				}
				s++;
			}
			// e--;
		}
		if (maxia > maxib) {
			cout << maxia;
		}
		else {
			cout << maxib;
		}




	}



}