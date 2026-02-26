#include <iostream>
using namespace std;
template<typename T>
class Vector {
public:
	T*a;
	int cs;
	int ts;
	Vector() {
		cs = 0;
		ts = 1;
		a = new T[ts];
	}
	vector(int x) {
		cs = 0;
		ts = x;
		a = new T[ts];
	}
	void Push_back(T x) {
		if (cs == ts) {
			T*b = a;
			a = new T[2 * ts];
			for (int i = 0; i < ts; i++) {
				a[i] = b[i];
			}
			ts *= 2;
			delete[]b;
		}
		a[cs] = x;
		cs++;
	}
	void Pop_back() {
		if (cs == 0) {
			cout << "Underflow\n";
			return;
		}
		T*b = a;
		a = new T[cs - 1];
		for (int i = 0; i < cs - 1; i++) {
			a[i] = b[i];
		}
		cs--;
		delete[]b;
	}
	int S_ize() {
		return cs;
	}
	int Capacity() {
		return ts;
	}
	int Front() {
		return a[0];
	}
	int Back() {
		return a[cs - 1];
	}
	T operator[](int i) {//again see we have overloaded [] operator
//because we know that we will be required to get the  value of vector at v[i] for which we need to return a[i] for which we need to overload the [] operator
		//also last time the = operator did not return anything we we wrote void
		//now the [] operator will return the T datatype so we need to write
		// T operator(int i)
		return a[i];
	}
};
//hence we have created or own vector using a class