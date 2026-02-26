#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int>v(5, 1);
	v.insert(v.begin() + 3, 3);
	cout << v.capacity();


}