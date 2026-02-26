#include <iostream>
#include<cstring>
using namespace std;
class car {
private:
	char* engine = new char[100]; //dynamic character array for engine
	int year;
	char name[100];
	string color;
public:
	//constructor :-
	car() {
		cout << "Inside my default constructor\n";
	}
	car (int year, char* name, string color, char*e) {
		cout << "Inside my parameterized constructor\n";
		this->year = year;
		strcpy(this->name, name);
		this->color = color;
		strcpy(this->engine, e);
	}
	car(car &x) {
		year = x.year;
		color = x.color;
		strcpy(name, x.name);
		engine = new char[strlen(x.engine) + 1];
		strcpy(engine, x.engine);
	}
	void set(int t, char* x, string y, char*e) {
		year = t;
		strcpy(this->name, x);
		color = y;
		strcpy(this->engine, e);
	}
	void print() {
		cout << year << endl << name << endl << color << endl << engine << endl;
		cout << "---------" << endl;
	}
};
int main() {
	car x;
	x.set(2025, "BMW\0", "Black", "V8\0");
	x.print();
	car y(2024, "Audi\0", "Pink", "V8\0");
	y.print();
	car z(y);
	y.set(2024, "Pudi\0", "Pink", "V9\0");
	y.print();
	z.print();
	/*
	Now we can see in the output that the copy constructor
	is copied correctly and the changed we made in the main constructor
	are not reflected in the copy constructor
	*/


}