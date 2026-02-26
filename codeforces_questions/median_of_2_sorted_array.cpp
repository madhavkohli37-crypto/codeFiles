#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>num1(n);
	vector<int>num2(m);
	for (int i = 0; i < n; i++) {
		cin >> num1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> num2[i];
	}
	// cout << num1[0];
	for (int i = 0; i < m; i++) {
		num1.push_back(num2[i]);
		num2.pop_back();
	}
	sort(num1.begin(), num1.end());
	if (num1.size() % 2 == 1) {
		int p = (num1.size() / 2) + 1;
		cout << num1[p] << endl;
	}
	else if (num1.size() % 2 == 0) {
		int p = (num1.size() / 2);
		cout << (num1[p] + num1[p + 1]) / 2 << endl;;
	}



}