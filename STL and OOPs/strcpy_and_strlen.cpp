#include <iostream>
#include<cstring>
char a[100];
using namespace std;
void F(char *c) {
	strcpy(a, c);
}
int main() {
	F("MadhavKohli\0");
	cout << a << endl;
	cout << strlen(a) << endl;//strlen() is used to
	//get the size of the character array
	char c[100];
	strcpy(c, "MadhavKohli\0");
	cout << c << endl;

}