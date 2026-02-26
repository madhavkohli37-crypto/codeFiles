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
	y = x;//again this is shallow copy assignment
	x.setter("2000CC\0");
	y.print();//We can see that this is shallow copy assignment
	// in the output


}