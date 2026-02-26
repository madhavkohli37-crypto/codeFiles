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
	z.print();/*-->From the output here we can clearly see that even
	though we have changed the arguements for object y only and have kept
	the arguements for z as the same after we have initialized the copy constructor z then also the engine for z has changed from V8 to V9 as it
	happened for constructor y but the name changed for y from Audi to
	 Pudi as we did it ourselfs but for z it remained Audi only which was
	 expected but engine change was not expected
	 THE NAME CHANGE AND ENGINE CHANGE BOTH WERE NOT EXPECTED BECAUSE
	 THE COPY CONSTRUCTOR WAS INITIALIZED BEFORE THE EDITING IN Y SO AFTER THE
	 COPY COMPLETED IN Z Z AND Y WERE INDEPENDENT CONSTRUCTORS AND DID NOT
	 DEPEND ON EACH OTHER'S VALUES

	*THIS HAPPENED BECAUSE COPY CONSTRUCTOR BY DEFAULT PERFORMS SHALLOW COPY*
*/



}