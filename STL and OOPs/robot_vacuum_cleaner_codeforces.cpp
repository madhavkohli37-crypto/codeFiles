#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
bool compare(string x, string y) {
	int count_s_x = 0, count_h_x = 0, count_s_y = 0, count_h_y = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 's') {
			count_s_x++;
		}
		if (x[i] == 'h') {
			count_h_x++;
		}
	}
	for (int i = 0; i < y.size(); i++) {
		if (y[i] == 's') {
			count_s_y++;
		}
		if (y[i] == 'h') {
			count_h_y++;
		}
	}
	return (count_s_x * count_h_y) > (count_s_y * count_h_x);
}
int32_t main() {
	int n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	int count = 0;
	int v = 0;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == 's') {
			for (int j = i + 1; j < ans.length(); j++) {
				if (ans[j] == 'h') {
					v++;
				}
			}
			break;
		}
	}
	//this can also be used as a general method to calculate the number of subsequence for a given string
	bool flag = 0;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == 's') {
			flag = 1;
			count += (v);
		}
		else if (ans[i] == 'h' and flag) {
			v--;
		}
	}
	cout << count << endl;



}