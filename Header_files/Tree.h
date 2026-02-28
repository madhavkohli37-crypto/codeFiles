#include<../Header_files/TreeNode.h>
template<typename T>
class Tree{
  public:
  TreeNode<T>*root;
  TreeNode<T>* buildTree() {
    // this tree creation method creates a tree such that if the input contains a value -1 then it will
    // be considered as a NULL node and it is created such that the traversal followed is
    // pre-order traversal
    T x;
    cin>>x;
    if(x==-1) {
      root=nullptr;
      return nullptr;
    }
    TreeNode<T>*a=new TreeNode<T>(x);
    a->left=buildTree();
    a->right=buildTree();
    root=a;
    return root;
  }
};