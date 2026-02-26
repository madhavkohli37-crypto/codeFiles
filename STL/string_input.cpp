#include <iostream>
#include<string>
using namespace std;
int main() {
	string x  {'x'};
	/*This might not work because
	we expect that string will be of multiple
	characters only.*/
	string x{"x"};/*This will work*/
	cout << x;


}