#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int longestCommonSubsequence(string s1, string s2) {
	if (s1.size() == 0 ) {
		return 0;
	}
	if ( s2.size() == 0) {
		return 0;
	}
	int count = 0;
	if (s1.front() == s2.front()) {
		string s_1 = s1;
		s_1.erase(s_1.begin());
		string s_2 = s2;
		s_2.erase(s_2.begin());
		count = 1 + longestCommonSubsequence(s_1, s_2);
	}
	else {
		string s_1 = s1;
		s_1.erase(s_1.begin());
		int op1 = longestCommonSubsequence(s_1, s2);
		string s_2 = s2;
		s_2.erase(s_2.begin());
		int op2 = longestCommonSubsequence(s1, s_2);
		count = max(op1, op2);
	}
	return count;

}
int main() {

	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubsequence(s1, s2);

}