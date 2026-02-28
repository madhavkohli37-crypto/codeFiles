//we could have directly created our tree by not making  class 
//and woring but just linking all the nodes and keeping the reference of just the root 
//pointer
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
TreeNode<int>*BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {

		TreeNode<int>*n = new TreeNode<int>(x);
		n->left = BuildTree();
		n->right = BuildTree();

		return n;
	}
}
int main() {
TreeNode<int>*root=BuildTree();

}

