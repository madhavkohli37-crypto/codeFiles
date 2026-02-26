#include"../Header_files/queue.h"
int main() {
	Queue<int>q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Pop();
	cout << q.Front() << endl;
}