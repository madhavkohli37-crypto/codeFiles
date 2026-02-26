/*This is the standard leetcode format in
 which we have to submit every code
 on leetcode just look out for the question
 container with most water on leetcode
 and you will understand yourself by the
 function maxArea they have created*/
#include <iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& h) {
	int s = 0, e = h.size() - 1, water, max_water = 0;
	while (s < e) {
		if (h[s] < h[e]) {
			water = h[s] * (e - s);
			s++;
			if (max_water < water) {
				max_water = water;
			}
		}
		else {
			water = h[e] * (e - s);
			e--;
			if (max_water < water) {
				max_water = water;
			}
		}
	}
	return max_water;

}
int main() {

	vector<int>height;
	int x;
	while (cin >> x) {
		height.push_back(x);
	}
	cout << maxArea(height) /*<< " Gallons"*/;


}