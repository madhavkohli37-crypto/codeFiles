/*foreward list is also called singly list*/
#include "../Header_files/listnode.h"
#include <algorithm>
template <typename T> class ForewardList {
public:
	void pushback(T data, ListNode<T>*& head) {
		ListNode<T>* a = new ListNode<T>(data);
		a->next = head;
		head = a;
	}
	void print(ListNode<T>* head) {
		while (head != NULL) {
			cout << head->value << " -> ";
			head = head->next;
		}
		cout << "NULL";
		cout << endl;
	}
	T sum(ListNode<T>* head) {
		if (head == NULL) {
			return 0;
		}
		T SUM;
		SUM = head->value + sum(head->next);
		return SUM;
	}
	int length(ListNode<T>* head) {
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
	T middleElement(ListNode<T>* head, int length) {
		int x = 0;
		while (x < length / 2) {
			x++;
			head = head->next;
		}
		return head->value;
	}
	T middleElement_fast(ListNode<T>* head) {
		ListNode<T>* f;
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
	void reverse(ListNode<T>*& head) {
		ListNode<T>* c = head;
		ListNode<T>* n;
		ListNode<T>* prev = NULL;
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
	ListNode<T>* reverse_recursively(ListNode<T>*& head) {
		if (head->next == NULL) {
			return head;
		}
		if (head == NULL) {
			return NULL;
		}
		ListNode<T>* reverse_head = reverse_recursively(head->next);
		head->next->next = head;
		head->next = NULL;
		return reverse_head;
	}
	ListNode<T>* reverseBetween(ListNode<T>* head, int left, int right) {
		if (head->next == NULL or left == right) {
			return head;
		}
		ListNode<T>* HEAD = head;
		ListNode<T>* o = head;
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
	bool check = 0;
	ListNode<T>* z;
	void exchange(ListNode<T>*& s, ListNode<T>*& e) {
		if (e == z) {
			swap(s->value, e->value);
			s = s->next;
			return;
		}
		exchange(s, e->next);
		if (check) {
			return;
		}
		if (s >= e) {
			check = 1;
			return;
		}
		swap(s->value, e->value);
		s = s->next;
		return;
	}
	ListNode<T>* reverseBetween_2(ListNode<T>* head, int left, int right) {
		if (left == right) {
			return head;
		}
		int x = left - 1, y = right - 1;
		ListNode<T>* s = head;
		ListNode<T>* e;
		z = head;
		while (x--) {
			s = s->next;
		}
		e = s;
		while (y--) {
			z = z->next;
		}
		exchange(s, e);
		return head;
	}
	bool hasCycle(ListNode<T>* head) {
		if (head == NULL) {
			return false;
		}
		if (head->next == NULL) {
			return false;
		}
		ListNode<T>* slow = head;
		ListNode<T>* fast = head;
		while (true) {
			if (fast->next == NULL) {
				break;
			}
			if (fast->next->next == NULL) {
				break;
			}
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
	ListNode<T>* detectCycle(ListNode<T>* head) {
		if (head == NULL) {
			return NULL;
		}
		if (head->next == NULL) {
			return NULL;
		}
		if (hasCycle(head)) {
			ListNode<T>* s = head;
			ListNode<T>* f = head;
			while (true) {
				s = s->next;
				f = f->next->next;
				if (s == f) {
					s = head;
					break;
				}
			}
			while (s != f) {
				s = s->next;
				f = f->next;
			}
			return s;
		} else {
			return NULL;
		}
	}
	void breakCycle(ListNode<T>*head) {
		if (!hasCycle(head)) {
			cout << "There is no cycle in this linked list\n";
			return;
		}
		else {
			ListNode<T>*n = detectCycle(head);
			ListNode<T>*tail = n;
			while (tail->next != n) {
				tail = tail->next;
			}
			tail->next = NULL;
			cout << "cycle break success!\n";
			return;
			/*
			cycle break succes!
			*/
		}
		return;
	}
	ListNode<T>* s;
#define check alpha
	bool check(ListNode<T>* n) {
		if (n->next == NULL) {
			if (s->value == n->value) {
				s = s->next;
				return true;
			} else {
				return false;
			}
		}
		if (check(n->next)) {
			if (s->value == n->value) {
				s = s->next;
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	bool isPalindrome(ListNode<T>* head) {
		s = head;
		return check(head);
	}
	void reorderList(ListNode<T>* head) {
		if (head == NULL) {
			return;
		}
		if (head->next == NULL) {
			return;
		}
		if (head->next->next == NULL) {
			return;
		}
		ListNode<T>* head_1 = head;
		ListNode<T>* head_2 = head;
		int n = length(head);
		n /= 2;
		int x = n - 1;
		ListNode<T>* help = head;
		while (n--) {
			head_2 = head_2->next;
		}
		head_2 = reverse_recursively(head_2);
		while (x--) {
			help = help->next;
		}
		help->next = NULL;
		ListNode<T>* prev_1 = NULL;
		ListNode<T>* prev_2 = NULL;
		while (true) {
			if (head_1->next == NULL) {
				head_1->next = head_2;
				break;
			}
			prev_1 = head_1->next;
			head_1->next = head_2;
			if (head_2->next == NULL) {
				head_2->next = head_1;
				break;
			}
			prev_2 = head_2->next;
			head_2->next = prev_1;
			head_1 = prev_1;
			head_2 = prev_2;
		}
		return;
	}
	ListNode<T>* oddEvenList(ListNode<T>* head) {
		if (head == NULL) {
			return head;
		}
		int length = 1;
		ListNode<T>*h = head;
		ListNode<T>*t = head;
		while (t->next != NULL) {
			t = t->next;
			length++;
		}
		length /= 2;
		while (true) {
			if (!length) {
				break;
			}
			length--;
			t->next = h->next;
			t = t->next;
			h->next = t->next;
			t->next = NULL;
			h = h->next;
		}
		return head;
	}
};