#include <iostream>
#include<string>
using namespace std;
int main() {
	string s{"hello world"};
// 	//to remove a single element
// 	// s.erase(s.begin() + 6);
// // to remove a range : -
// 	s.erase(s.begin() + 2, s.begin() + 5);
// 	cout << s;
	// witho	ut iterators :-
	// s.erase(2);//erase from index 2 to the end
	// cout << s;
	s.erase(2, 3); //remove 3 characters from index 2 onwards
	cout << s;



}