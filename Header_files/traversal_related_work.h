#include<algorithm>
#include"TreeNode.h"
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
  int height(TreeNode<T>*root) {
    if(root==NULL) {
      return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
  }
  int count_nodes(TreeNode<T>*root) {
    if(root==NULL) {
      return 0;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
  }
  int sumofNodes(TreeNode<T>*root) {
    if(root==NULL) {
      return 0;
    }
    return root->value+sumofNodes(root->left)+sumofNodes(root->right);
  }
  void invertTree(TreeNode<T>* root) {
        if (root == NULL) {
            return;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return;
    }
};