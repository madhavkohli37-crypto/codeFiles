#include <iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << v.size() << endl;//before removing
	// removing a single element :-
	v.erase(v.begin() + 5);
	// removing a range :-
	// v.erase(v.begin() + 1, v.begin() + 5);
	cout << v.size() << endl;//after removing
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}



}