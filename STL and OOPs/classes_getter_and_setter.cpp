#include <iostream>
#include<string>
using namespace std;
class car {
private:
	long long cost = 100000;
	string name;
public:
	void set_name(string x) {
		name = x;
	}
	void set_cost(int x) {
		cost = x;
	}
	void print() {
		cout << cost << endl << name << endl;
		cout << "-----------" << endl;
	}
};
int main() {
	car y;
	y.set_name("BMW");
	y.print();
	y.set_cost(50000);
	y.print();




}