#include <iostream>
#include<stack>
using namespace std;
int main() {

	stack<int>st;
	st.push(1);
	st.push(2);
	cout << st.empty() << endl;
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
}