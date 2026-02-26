#include <iostream>
using namespace std;
template<typename T>
class ListNode {
public:
	T value;
	ListNode*next;
	ListNode() {
		value = 0;
		next = NULL;
	}
	ListNode(T x) {
		this->value = x;
		next = NULL;
	}

};