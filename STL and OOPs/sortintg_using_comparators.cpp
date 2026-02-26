#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
class friends {
public:
	string name;
	int money;
	// friends() {

	// }
	// friends(string name, int money) {
	// 	this->name = name;
	// 	this->money = money;
	// }
};
bool compare(friends a, friends b) {
	return (a.money < b.money);
}//this is our compare function
int main() {

	friends a[5];
	for (int i = 0; i < 5; i++) {
		cin >> a[i].name >> a[i].money;
	}
	sort(a, a + 5, compare);//this will sort our object a on the basis of money
	//compare is just a way of telling the compiler how to sort the container/object
	for (int i = 0; i < 5; i++) {
		cout << a[i].name << " " << a[i].money << endl;
	}


}