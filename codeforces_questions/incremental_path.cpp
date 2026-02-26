/*This code needs optimisation
*/
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define int long long
// bool check(int x, int y) {
// 	return (x > y);
// }
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int>v(m);
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		vector<int>white;
		int j = 2;
		while (white.size() != 100000 ) {
			if (binary_search(v.begin(), v.end(), j) == 0) {
				white.push_back(j);
			}
			j++;
		}
		// sort(white.begin(), white.end());
		// for (int i = 0; i < n ; i++) {
		// 	cout << white[i] << " ";
		// }
		// cout << endl;
		// for (int i = 0; i < m; i++) {
		// 	cout << v[i] << " ";
		// }
		// cout << endl;
		for (int i = 0; i < n; i++) {
			int k = 1, flag;
			for (int j = 0; j <= i; j++) {
				if (s[j] == 'A') {
					k++;
					flag = 0;
				}
				else if (s[j] == 'B') {
					k = white[upper_bound(white.begin(), white.end(), k) - white.begin()];
					flag = 1;
				}
			}
			if (flag == 1) {
				int index = (lower_bound(white.begin(), white.end(), k) - white.begin());
				white.erase(white.begin() + index);
			}
			sort(v.begin(), v.end());
			if (binary_search(v.begin(), v.end(), k) == 0) {
				v.push_back(k);
			}
		}
		sort(v.begin(), v.end());
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;

	}

}