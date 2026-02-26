#include <iostream>
using namespace std;
template<typename T>
class ListNode {
public:
	T value;
	ListNode<T>*next;
	ListNode() {
		this->value = 0;
		next = NULL;
	}
	ListNode(T value) {
		this->value = value;
		next = NULL;
	}
	// void operator=(ListNode<T>x) {
	// 	this->value = x.value;
	// 	this->next = x.next;
	// }
};
template<typename T>
class ForewardList {
public:
	void pushback(T data, ListNode<T>*&head) {
		ListNode<T>*a = new ListNode<T>(data);
		a->next = head;
		head = a;
	}
	void print(ListNode<T>*head) {
		while (head != NULL) {
			cout << head->value << " -> ";
			head = head->next;
		}
		cout << "NULL";
		cout << endl;
	}
	T sum(ListNode<T>*head) {
		if (head == NULL) {
			return 0;
		}
		T SUM;
		SUM = head->value + sum(head->next);
		return SUM;
	}
	int length(ListNode<T>*head) {
		int length = 0;
		if (head == NULL) {
			return length;
		}
		while (head != NULL) {
			length++;
			head = head->next;
		}
		return length;
	}
	T middleElement(ListNode<T>*head, int length) {
		int x = 0;
		while (x < length / 2) {
			x++;
			head = head->next;
		}
		return head->value;
	}
	T middleElement_fast(ListNode<T>*head) {
		ListNode<T>*f;
		ListNode<T>* s;
		f = head, s = head;
		while (f->next != NULL) {
			f = f->next->next;
			s = s->next;
			if (f == NULL) {
				return s->value;
			}
		}
		return s->value;
	}
	void reverse(ListNode<T>*&head) {
		ListNode<T>*c = head;
		ListNode<T>*n;
		ListNode<T>*prev = NULL;
		while (c->next != NULL) {
			n = c->next;
			c->next = prev;
			prev = c;
			c = n;
			head = c;
		}
		c->next = prev;
		return;
	}
	ListNode<T>* reverse_recursively(ListNode<T>*&head) {
		if (head->next == NULL) {
			return head;
		}
		if (head == NULL) {
			return NULL;
		}
		ListNode<T>*reverse_head = reverse_recursively(head->next);
		head->next->next = head;
		head->next = NULL;
		return reverse_head;
	}
	ListNode<T>* reverseBetween(ListNode<T>* head, int left, int right) {
		if (head->next == NULL or left == right) {
			return head;
		}
		ListNode<T>*HEAD = head;
		ListNode<T>*o = head;
		int x = 1 + right - left;
		ListNode<T>* n = NULL;
		ListNode<T>* c;
		ListNode<T>* previous = NULL;
		left--;
		if (left >= 1) {
			left--;
			while (left--) {
				head = head->next;
			}
			o = head;
			head = head->next;
		}
		c = head;
		while (x--) {
			n = c->next;
			c->next = previous;
			previous = c;
			c = n;
		}
		if (o == head) {
			head->next = n;
			return previous;
		}
		o->next = previous;
		head->next = n;
		return HEAD;
	}
};
int main() {

	ListNode<int>*head = NULL;
	ForewardList<int> l;
	l.pushback(1, head);
	l.pushback(2, head);
	l.pushback(3, head);
	l.pushback(4, head);
	l.pushback(5, head);
	l.pushback(6, head);
	l.pushback(7, head);
	l.print(head);
	cout << l.sum(head) << endl;
	cout << l.length(head) << endl;
	cout << l.middleElement_fast(head) << endl;
	l.reverse(head);
	l.print(head);
	cout << endl;
	cout << "Reversed again\n_______________________________\n\n";
	head = l.reverse_recursively(head);
	l.print(head);

}