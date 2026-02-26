#include <iostream>
using namespace std;
#define MAX 1000
template<typename T>
class Stack {
public:
	T a[MAX];
	int topofstack;
	Stack() {
		topofstack = -1;
	}
	void Push(T x) {
		if (topofstack == MAX) {
			cout << "STACK OVERFLOW\n";
			return;
		}
		topofstack++;
		a[topofstack] = x;
		return;
	}
	void Pop() {
		if (topofstack == -1) {
			cout << "STACK UNDERFLOW\n";
			return;
		}
		topofstack--;
		return;
	}
	bool Empty() {
		return (topofstack == -1);
	}
	T Top() {
		if (topofstack == -1) {
			cout << "NO ELEMENT\n";
			return -1;
		}
		return a[topofstack];
	}
};