#include <bits/stdc++.h>
using namespace std;
class car {
	char* engine = new char [100];
public:
	void setter(char*x) {
		strcpy(this->engine, x);
	}
	int cost;
	string name;
	void operator=(car &t) {
		name = t.name;
		cost = t.cost;
		engine = new char[strlen(t.engine) + 1];
		strcpy(this->engine, t.engine);
	}
	void print() {
		cout << cost << endl << name << endl << engine << endl;
		cout << "-------------\n";
	}
};
int main() {
	car x;
	x.cost = 50000;
	x.name = "KIA";
	x.setter("1500CC\0");
	x.print();
	car y;
	y = x;
	x.setter("2000CC\0");
	x.print();
	y.print();//We can see that this is deep copy assignment
	// in the output


}