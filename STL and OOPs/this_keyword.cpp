#include <iostream>
#include<string>
using namespace std;
class car {
private:
	int year;
	string name;
	string color;
public:
	//constructor :-
	car() {
		cout << "Inside my default constructor\n";
	}
	car (int year, string name, string color) {
		cout << "Inside my parameterized constructor\n";
		this->year = year;
		this->name = name;
		this->color = color;
	}
	void set(int t, string x, string y) {
		year = t;
		name = x;
		color = y;
	}
	void print() {
		cout << year << endl << name << endl << color << endl;
		cout << "---------" << endl;
	}
};
int main() {
	car x;
	x.set(2025, "BMW", "Black");
	x.print();
	car y(2024, "Audi", "Pink");
	y.print();



}