#include"../Header_files/foreward_list.h"
int main() {
	ListNode<int>*head = NULL;
	int n;
	cin >> n;
	ForewardList<int> l;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		l.pushback(x, head);
	}
	// ListNode<int>*tail = head;
	// while (tail->next != NULL) {
	// 	tail = tail->next;
	// }
	// tail->next = head;
	// cout << l.hasCycle(head) << endl;
	// l.breakCycle(head);
	// cout << l.hasCycle(head) << endl;
	// l.breakCycle(head);
	// cout << l.isPalindrome(head) << endl;
	// l.reorderList(head);
	l.print(head);

}