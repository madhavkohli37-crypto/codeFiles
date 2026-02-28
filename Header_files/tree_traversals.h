#include<iostream>
using namespace std;
template<typename T>
class TreeNode{
public:
T value;
TreeNode*left;
TreeNode*right;
TreeNode(){
this->value=0;
left=nullptr;
right=nullptr;
}
TreeNode(T value){
this->value=value;
left=nullptr;
right=nullptr;
}
};
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
  void preorder(TreeNode<T>*root) {
    if(root==NULL) {
      return;
    }
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
  }
  void inorder(TreeNode<T>*root) {
    if(root==NULL) {
      return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
    return;
  }
  void postorder(TreeNode<T>*root) {
    if(root==NULL) {
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
    return;
  }
};