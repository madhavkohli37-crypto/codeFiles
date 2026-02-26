#include <iostream>
using namespace std;
template<typename T>//templates can be use for any
// kind of datatypes and hence we can use tmplates
// for generic programming
T sum(T x, T y) {
	return x + y;
}
int main() {
	char a, b;
	cin >> a >> b;
	cout << sum(a, b);


}