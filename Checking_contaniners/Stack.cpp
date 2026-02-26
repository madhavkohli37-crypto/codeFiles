#include"../Header_files/Stack.h"
int main() {
	Stack<int>st;
	int x;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		st.Push(x);
	}
	for (int i = 0; i <= 10; i++) {
		cout << st.Top() << endl;
		st.Pop();
	}


}