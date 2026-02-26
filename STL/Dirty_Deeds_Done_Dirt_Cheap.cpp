#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int k = 0;
class Pair {
public:
	int index;
	int x;
	int y;
	void getter() {
		cout << x << " " << y << " " << index << endl;
	}
	Pair() {

	}
};
bool compare_1(Pair p, Pair q) {
	return (p.y < q.y);
}
bool compare_2(Pair p, Pair q) {
	return (p.y > q.y);
}
int main() {
	int n;
	cin >> n;
	vector<Pair>a_1;
	vector<Pair>a_2;
	for (int i = 0; i < n; i++) {
		Pair a;
		a.index = i + 1;
		cin >> a.x >> a.y;
		if (a.x > a.y) {
			a_1.push_back(a);
		}
		else if (a.x < a.y) {
			a_2.push_back(a);
		}
	}
	// for (int i = 0; i < a_1.size(); i++) {
	// 	a_1[i].getter();
	// }
	if (a_1.size() > a_2.size()) {
		cout << a_1.size() << endl;
		sort(a_1.begin(), a_1.end(), compare_1);
		for (int i = 0; i < a_1.size(); i++) {
			cout << a_1[i].index << " ";
		}
		cout << endl;
	}
	else if (a_1.size() <= a_2.size()) {
		cout << a_2.size() << endl;
		sort(a_2.begin(), a_2.end(), compare_2);
		for (int i = 0; i < a_2.size(); i++) {
			cout << a_2[i].index << " ";
		}
		cout << endl;
	}
}