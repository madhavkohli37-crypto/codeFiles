#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	int height[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	int water[n + 5] {0};
	int maxi = 0;
	int s = 1, e = n;
	while (s < e) {
		if (height[s] < height[e]) {
			water[s] = (e - s) * height[s];
			s++;
		}
		else if (height[e] <= height[s]) {
			water[e] = (e - s) * height[e];
			e--;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (maxi < water[i]) {
			maxi = water[i];
		}
	}

	cout << maxi;

}