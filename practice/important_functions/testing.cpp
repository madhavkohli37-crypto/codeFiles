#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	cin.tie(NULL);
	cout << "hello";   // stays in buffer
	_exit(0);          // immediate exit, no flushing
}
