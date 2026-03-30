#include"HashMap.h"
int main() {
	HashMap<int>h;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		h.insert(s, x);
	}
	h.print();
}
