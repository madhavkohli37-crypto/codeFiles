//pair comes in the utility header file
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<pair<int, int>>v; //we have crreated our pair
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	cout << v[0].first << " " << v[0].second << endl;
	/*pair<int, int>p;
	p = make_pair(3, 5);
	cout << p.first << " " << p.second << endl;*/
}

