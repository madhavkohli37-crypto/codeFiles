#include <iostream>
#include<math.h>
#include<vector>
using namespace std;
int factorial (int n) {
	int ans = 1;
	while (n) {
		ans *= n;
		n--;
	}
	return ans;
}
int main() {
	vector<vector<int>>v(2, {1, 2, 3});
	cout << v[1][1];

}