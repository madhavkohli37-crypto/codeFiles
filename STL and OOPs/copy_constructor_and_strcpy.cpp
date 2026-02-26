#include <iostream>
#include<cstring>
using namespace std;
class car {
private:
	int year;
	char name[100];
	string color;
public:
	//constructor :-
	car() {
		cout << "Inside my default constructor\n";
	}
	car (int year, char* name, string color) {
		cout << "Inside my parameterized constructor\n";
		this->year = year;
		strcpy(this->name, name);
		this->color = color;
	}
	void set(int t, char* x, string y) {
		year = t;
		strcpy(this->name, x);
		color = y;
	}
	void print() {
		cout << year << endl << name << endl << color << endl;
		cout << "---------" << endl;
	}
};
int main() {
	car x;
	x.set(2025, "BMW\0", "Black");
	x.print();
	car y(2024, "Audi\0", "Pink");
	y.print();
	car z(y);
	z.print();//-->This is a copy constructor
	//it is already made by the c++ authors
	//THIS WILL INVOKE COPY CONSTRUCTOR



}