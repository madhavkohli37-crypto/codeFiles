#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
void F(string s, int i) {
	if (i == s.size()) {
		cout << s << endl;
		return;
	}
	for (int j = i; j < s.size(); j++) {
		swap(s[i], s[j]);
		F(s, i + 1);
	}
	return;
}
int main() {
	cin >> s;
	F(s, 0);


}