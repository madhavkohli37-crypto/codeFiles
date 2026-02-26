#include <iostream>
#include<algorithm>
#include<vector>
#include<vector>
using namespace std;
// bool isPossibleToSplit(vector<int>& v) {
// 	auto maxi = *max_element(&v[0], &v[5]);
// 	vector<int>frequency(maxi + 1);
// 	for (int i = 0; i < v.size(); i++) {
// 		frequency[v[i]]++;
// 		if (frequency[v[i]] > 1) {
// 			return false;
// 		}
// 	}
// 	return true;
// }
int main() {
	int x = 2, y = 4;
	bool a = (y > x), b = (y > x + 1), c = (y >= x + 2);
	if (a and b and c) {
		cout << "Hi";
	}
	else {
		cout << "Bye";
	}





}