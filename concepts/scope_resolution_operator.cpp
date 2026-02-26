#include <iostream>
#include<vector>
using namespace std;
namespace A {
int y = 0;
}
namespace B {
int y = 1;
}
int x = 10;
int main() {

	int x = 5;
	cout << x << endl;//this will print the main function x
	cout <<::x << endl; //this will print the global x
	cout << B::y << endl;//::is used to resolve the namespaces
	vector<int>v(3, 5);
	vector<int>::iterator it = v.begin();

}
//another use of scope resolution operator is to resolve the namespaces
