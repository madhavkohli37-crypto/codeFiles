#include<iostream>
#include<climits>
using namespace std;
int n;
int a[200001];

int F(int i) {

	//Stopping Point:
	if (i == n) {
		//If I am here I am at a state F(n) and its
		//answer will be zero.
		return 0;
	}

	//Currently We are trying to solve for the ith
	//state. or F(i).

	//When you take one step jump.
	int Op1 = abs(a[i] - a[i + 1]) + F(i + 1);


	int Op2 = INT_MAX;
	if (i + 2 <= n) {
		//When you take two step jump.
		Op2 = abs(a[i] - a[i + 2]) + F(i + 2);
	}

	//Current state answer : i.e. F(i) will be :
	return min(Op1, Op2);
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}


	cout << F(1) << endl; //Minimum Cost from 1 to nth stone.
}