#include"../Header_files/foreward_list.h"
using namespace std;
int main() {
	ListNode<int>*head = NULL;
	ForewardList<int> l;
	l.pushback(1, head);
	l.pushback(2, head);
	l.print(head);


}