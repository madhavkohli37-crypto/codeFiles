#include<algorithm>
#include"TreeNode.h"
#include<utility>
template<typename T>
class Tree{
  public:
  TreeNode<T>*root;
  int diameter;
  Tree() {
    root=nullptr;
    diameter=0;
  }
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
    diameter=max(diameter,h1+h2);
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
    int Diameter1(TreeNode<T>*root) {
      //computation of this function is O(n*n);
      if(root==NULL) {
        return 0;
      } 
      int op1=Diameter1(root->left);
      int op2=Diameter1(root->right);
      int op3=height(root->left)+height(root->right);
      return max((op1,op2),op3);
    }
     int Diameter2(TreeNode<T>*root) {
      //computation of this function is O(1);
      if(root==NULL) {
        return 0;
      }
    return diameter;
    }
    pair<int,int> Diameter3(TreeNode<T>*root) {
      pair<int,int> x;
      if(root==NULL) {
        x.first=0;
        x.second=0;
        return x;
      }
      pair<int,int>LSI=Diameter3(root->left);
      pair<int,int>RSI=Diameter3(root->right);
      x.first=LSI.second+RSI.second;
      x.second=1+max(LSI.second,RSI.second);
      return x;
    }
    pair<bool,int> HBT(TreeNode<T>*root) {
      pair<bool,int>x;
      if(root==NULL) {
        x.first=true;
        x.second=0;
        return x;
      }
      pair<bool,int>LSI=HBT(root->left);
      pair<bool,int>RSI=HBT(root->right);
      x.second=1+max(LSI.second,RSI.second);
      if(abs(LSI.second-RSI.second)<=1 and LSI.first and RSI.first) {
        x.first=true;
      }
      else {
        x.second=false;
      }
      return x;
    }
  TreeNode<T>* createHBT(T*a,int s,int e) {
    if(s>e) {
      return NULL;
    }
    int mid=(s+e)/2;
      int rootNode=a[mid];
      TreeNode<T>*x=new TreeNode<T>(rootNode);
      x->left=createHBT(a,s,mid-1);
      x->right=createHBT(a,mid+1,e);
      return x;
    }
    void printkthlevel(TreeNode<T>*root,int k) {
      if(root==NULL) {
        return;
      }
      if(k==1) {
        cout<<root->value<<" ";
        return;
      }
      cout<<root->value<<" ";
      k--;
      printkthlevel(root->left,k);
      printkthlevel(root->right,k);
      return;
    }
    void printalllevels(TreeNode<T>*root) {
      int h=height(root);
      for(int i=1;i<=h;i++) {
        printkthlevel(root,i);
        cout<<endl;
      }
    }
};
