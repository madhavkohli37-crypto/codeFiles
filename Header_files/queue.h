#include <iostream>
using namespace std;
#define MAX 1000
template<typename T>
class Queue {
public:
	T* a;
	int cs, ts, front, back;
	Queue() {
		cs = 0, ts = MAX, front = -1, back = -1;
		a = new T[ts];
	}
	Queue(int size) {
		cs = 0, ts = size, front = -1, back = -1;
		a = new T[ts];
	}
	void Push(T x) {
		if (cs == ts) {
			cout << "OVERFLOW\n";
			return;
		}
		if (cs == 0) {
			front = 0;
		}
		back = (back + 1) % ts;
		a[back] = x;
		cs++;
		return;
	}
	void Pop() {
		if (cs == 0) {
			cout << "UNDERFLOW\n";
			return;
		}
		if (cs == 1) {
			front = back = -1;
		}
		else {
			front = (front + 1) % ts;
		}
		cs--;
		return;
	}
	T Front() {
		return a[front];
	}
	bool empty() {
		return (cs == 0);
	}
};