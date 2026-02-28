#include<iostream>
using namespace std;

template<typename T>
class TreeNode {
public:
	T val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() {
		left = nullptr;
		right = nullptr;
	}

	TreeNode(T x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

