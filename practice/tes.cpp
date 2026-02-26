#include <iostream>
#include<iomanip>
using namespace std;
int main() {

	float a = 1.20001;
	cout << fixed << setprecision(3) << a;
}