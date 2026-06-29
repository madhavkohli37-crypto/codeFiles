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
		// this keyword is used to access the parameter of the class not the function i.e. in this case this is used to access the year of the car class not the year passed in the function
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
