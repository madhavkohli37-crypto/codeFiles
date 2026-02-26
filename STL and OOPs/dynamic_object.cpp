#include <iostream>
#include<cstring>
using namespace std;
class car {
	int cost;
	char name[100];
	char*engine = new char [100];
public:
	void setter(int cost, char*engine, char*name) {
		this->cost = cost;
		strcpy(this->name, name);
		strcpy(this->engine, engine);
		return;
	}
	void getter() {
		cout << name << endl << cost << endl << engine << endl;
		cout << "----------------\n";
		return;
	}
	car() {

	}
	car(int cost, char*name, char*engine) {
		this->cost = cost;
		strcpy(this->name, name);
		strcpy(this->engine, engine);
	}
	void operator=(car &x) {
		this->cost = x.cost;
		strcpy(this->name, x.name);
		engine = new char[strlen(x.engine) + 1];
		strcpy(this->engine, x.engine);
	}
};
int main() {

	car*p = new car(100000, "BMW\0", "V12\0"); //we have created our dynamic object
	(*p).getter();//either this way we can get the data members and functions of the dynamic object
	cout << endl;
	p->getter();//or this way we can get the data members and member functions of the dynamic object
	delete p;//this deletes the complete dynamic object
	// cout << "hi";


}