#include"Tree.h"
int main() {
  Tree<int> t;
  t.buildTree();
  t.preorder(t.root);
  cout<<endl;
  t.inorder(t.root);
  cout<<endl;
  t.postorder(t.root);
  cout<<endl;
  cout<<t.height(t.root)<<endl;
  cout<<t.count_nodes(t.root)<<endl;
  cout<<t.sumofNodes(t.root)<<endl;
  t.invertTree(t.root);
  t.preorder(t.root);
  cout<<endl;
  cout<<t.Diameter1(t.root)<<endl;//slower
  cout<<t.Diameter2(t.root)<<endl;//faster
  cout<<t.Diameter3(t.root).first<<" "<<t.Diameter3(t.root).second<<endl;//faster and returns pair
  cout<<t.HBT(t.root).first<<" "<<t.HBT(t.root).second<<endl;
  int a[]{1,2,3,4,5,6,7,8,9,10};
  TreeNode<int>*ROOT=t.createHBT(a,0,9);
  t.preorder(ROOT);
  cout<<endl;
  cout<<t.HBT(ROOT).first<<endl;
  t.printkthlevel(ROOT,4);
  cout<<endl;
  t.printalllevels(ROOT);
}
