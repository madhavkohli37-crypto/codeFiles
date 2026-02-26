#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	// find() returns the iterator(in case of array the address of the first occurance of the element we have entered and in case we do not find the element it returns the last index like in case of array it returns a+n )
	// it can we used on unsorted data also and hence it has a linear computations

	int a[] {1, 2, 3, 4, 5, 2, 3, 4, 7};
	int*p = find(a, a + 9, 1);
	cout << p - a;

}