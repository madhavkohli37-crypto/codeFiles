#include"../Header_files/vector.h"
int main() {
	Vector<int>v;
	v.Push_back(5);
	v.Push_back(7);
	v.Push_back(8);
	v.Pop_back();
	cout << v[0] << endl << v[1] << endl;
	cout << v.Capacity();
}