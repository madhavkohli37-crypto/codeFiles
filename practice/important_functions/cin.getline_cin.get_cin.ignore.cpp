#include <iostream>
using namespace std;
int main() {

	char a[100];
	char n;
	int i = 0;
	// cin.getline(a, 50, 'y');//-->This will work
	// cout << a;
	// cin.get(a);-->This will not work
	// cout << a;
	/*
	The reason for this is that cin.getline function works
	on a character array but cin.get function does only
	work on single character
	*/
	while (cin.get(n)) {
		if (n == '\n') {
			break;
		}
		a[i] = n;
		i++;
	}
	// cin.ignore();
	// cin.ignore();
	a[i] = '\0';
	cout << a ;
	// cout<< endl;
	/*after above line the a array is sent to
	the output buffer but we might not be able to
	se this at the output screen*/
	cin.get();
}