// now also it is working
#include <iostream>
using namespace std;
int x, y;
int answer(int i) {
	/*alternative :-
	if(i==y) {
	return 1;
	}
	*/
	if (i == y - 1) {
		return x;
	}
	else {
		return x * (answer(i + 1));
	}

}
int main() {
	cin >> x >> y;
	cout << answer(0);

}