#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int height[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	int s = 1, e = n;
	int water[100076] {0};
	int i = 1;
	while (s < e) {
		while (s < e) {
			if (height[s] > height[e]) {
				water[i] = (height[e]) * (e - s);
				i++;
			}
			else {
				water[i] = (height[s]) * (e - s);
				i++;
			}
			e--;
		}
		s++;
		e = n;
	}
	int maxi = 0;
	for (int i = 1; i <= 100076; i++) {
		if (water[i] > maxi) {
			maxi = water[i];
		}
	}
	cout << maxi;

}