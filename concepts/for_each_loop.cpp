#include <iostream>
#include<utility>
#include<string>
#include<vector>
using namespace std;
int main() {

	vector<pair<int, string>>v;
	v.push_back({1, "Madhav"});
	v.push_back({2, "Bhoomi"});
	v.push_back({3, "Jyoti"});
	v.push_back({4, "Pawan"});
	// for (auto x : v) {
	// 	cout << x.first << " " << x.second << endl;
	// }
	/*
	x voh hai jo v ka har eek element hai jaise v ka har
	eek element eek pair hai toh x is a pair here
	for better understandability we can write :-
	*/
	for (pair<int, string> x : v) {
		cout << x.first << " " << x.second << endl;
	}
	cout << endl;

}