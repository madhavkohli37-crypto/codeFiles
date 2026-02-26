#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	int input[3];
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}
	sort(input, input + 3);
	int a = input[0];
	int b = input[1];
	int c = input[2];
	vector<int>ans;
	if ((b / a) % c)


	}