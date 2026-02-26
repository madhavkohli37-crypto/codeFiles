#include <iostream>
#include<cstring>
using namespace std;
int main() {

	char op[100][100] {'\0'};
	memset(op, '1', sizeof(op));
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << op[i][j] << " ";
		}
		cout << endl;
	}
}