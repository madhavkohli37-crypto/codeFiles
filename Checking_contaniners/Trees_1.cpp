#include"../Header_files/Tree.h"
int main() {
  Tree<int> t;
  t.buildTree();
  cout<<t.root->left->value;
}
