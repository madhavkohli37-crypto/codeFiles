#include "TreeNode.h"
#include <algorithm>
#include <queue>
#include <utility>
template <typename T> class Tree {
public:
    TreeNode<T>* root;
    int diameter;
    Tree() {
        root = nullptr;
        diameter = 0;
    }
    TreeNode<T>* buildTree() {
        // this tree creation method creates a tree such that if the input
        // contains a value -1 then it will be considered as a NULL node and it
        // is created such that the traversal followed is pre-order traversal
        T x;
        cin >> x;
        if (x == -1) {
            root = nullptr;
            return nullptr;
        }
        TreeNode<T>* a = new TreeNode<T>(x);
        a->left = buildTree();
        a->right = buildTree();
        root = a;
        return root;
    }
    void preorder(TreeNode<T>* root) {
        if (root == NULL) {
            return;
        }
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
        return;
    }
    void inorder(TreeNode<T>* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
        return;
    }
    void postorder(TreeNode<T>* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
        return;
    }
    int height(TreeNode<T>* root) {
        if (root == NULL) {
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        diameter = max(diameter, h1 + h2);
        return 1 + max(h1, h2);
    }
    int count_nodes(TreeNode<T>* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }
    int sumofNodes(TreeNode<T>* root) {
        if (root == NULL) {
            return 0;
        }
        return root->value + sumofNodes(root->left) + sumofNodes(root->right);
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
    int Diameter1(TreeNode<T>* root) {
        // computation of this function is O(n*n);
        if (root == NULL) {
            return 0;
        }
        int op1 = Diameter1(root->left);
        int op2 = Diameter1(root->right);
        int op3 = height(root->left) + height(root->right);
        return max((op1, op2), op3);
    }
    int Diameter2(TreeNode<T>* root) {
        // computation of this function is O(1);
        if (root == NULL) {
            return 0;
        }
        return diameter;
    }
    pair<int, int> Diameter3(TreeNode<T>* root) {
        pair<int, int> x;
        if (root == NULL) {
            x.first = 0;
            x.second = 0;
            return x;
        }
        pair<int, int> LSI = Diameter3(root->left);
        pair<int, int> RSI = Diameter3(root->right);
        x.first = LSI.second + RSI.second;
        x.second = 1 + max(LSI.second, RSI.second);
        return x;
    }
    pair<bool, int> HBT(TreeNode<T>* root) {
        pair<bool, int> x;
        if (root == NULL) {
            x.first = true;
            x.second = 0;
            return x;
        }
        pair<bool, int> LSI = HBT(root->left);
        pair<bool, int> RSI = HBT(root->right);
        x.second = 1 + max(LSI.second, RSI.second);
        if (abs(LSI.second - RSI.second) <= 1 and LSI.first and RSI.first) {
            x.first = true;
        } else {
            x.second = false;
        }
        return x;
    }
    TreeNode<T>* createHBT(T* a, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int mid = (s + e) / 2;
        int rootNode = a[mid];
        TreeNode<T>* x = new TreeNode<T>(rootNode);
        x->left = createHBT(a, s, mid - 1);
        x->right = createHBT(a, mid + 1, e);
        return x;
    }
    void printkthlevel(TreeNode<T>* root, int k) {
        if (root == NULL) {
            return;
        }
        if (k == 1) {
            cout << root->value << " ";
            return;
        }
        printkthlevel(root->left, k - 1);
        printkthlevel(root->right, k - 1);
        return;
    }
    void printalllevels(TreeNode<T>* root) {
        int h = height(root);
        for (int i = 1; i <= h;
             i++) { // because number of levels = height of tree
            printkthlevel(root, i);
            cout << endl;
        }
    }
    void bfs(TreeNode<T>* root) {
        queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode<T>* temp = q.front();
            q.pop();
            cout << temp->value << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
    void bfs2(TreeNode<T>* root) {
        queue<TreeNode<T>*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode<T>* temp = q.front();
            q.pop();
            if (temp == NULL) {
                if (!q.empty()) {
                    q.push(NULL);
                    cout << endl;
                }
            } else {
                cout << temp->value << " ";
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
    }
    TreeNode<T>* BuildTreefromIOPO(T*pre,T*in,int s,int e) {
      if(s>e) {
        return NULL;
      }
      static int i=0;
      TreeNode<T>*x=new TreeNode<T>(pre[i]);
      int index=-1;
      for(int j=s;j<=e;j++) {
        if(in[j]==pre[i]) {
          index=j;
          break;
        }
      }
      i++;
      x->left=BuildTreefromIOPO(pre,in,s,index-1);
      x->right=BuildTreefromIOPO(pre,in,index+1,e);
      return x;
    }
     vector<vector<T>> bfs3(TreeNode<T>* root) {
      vector<vector<T>> ans;
      vector<T> t;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode<T>*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode<T>* temp = q.front();
            q.pop();
            if (temp == NULL) {
                if (!q.empty()) {
                    q.push(NULL);
                    ans.push_back(t);
                    t.clear();
                } else {
                    ans.push_back(t);
                }
            } else {
                t.push_back(temp->value);
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
    vector<T> LeftView(TreeNode<T>*root) {
      vector<T> ans;
      if(root==NULL) {
        return ans;
      }
      vector<vector<T>>help=bfs3(root);
      for(int i=0;i<help.size();i++) {
        ans.push_back(help[i][0]);
      }
      return ans;
    }
    vector<T> RightView(TreeNode<T>*root) {
      vector<T> ans;
      if(root==NULL) {
        return ans;
      }
      vector<vector<T>>help=bfs3(root);
      for(int i=0;i<help.size();i++) {
        ans.push_back(help[i][help[i].size()-1]);
      }
      return ans;
    }
    int fl=0;
vector<T>ans;
void rightSideView_1(TreeNode<T>* root,int cl) {
    if(root==NULL) {
        return;
    }
    if(cl>fl) {
        ans.push_back(root->val);
        fl++;
    }
    rightSideView_1(root->right,cl+1);
    rightSideView_1(root->left,cl+1);
    return;
}
    vector<T> rightSideView(TreeNode<T>* root) {
        rightSideView_1(root,1);
        return ans;
    }
    TreeNode<T>* insertinBST(TreeNode<T>*root,T value) {
      if(root==nullptr) {
        TreeNode<T>*x=new TreeNode(value);
        return x ;
      }
      if(value==-1) {
        return nullptr;
      } 
      if(value>root->value) {
        root->right=insertinBST(root->right,value);
      }
      else {
        root->left=insertinBST(root->left,value);
      }
      return root;
    }
    TreeNode<T>* createBST() {
      int x;
      cin>>x;
      if(x==-1) {
        return nullptr;
      }
      TreeNode<T>*root=new TreeNode(x);
      int temp;
      while(cin>>temp) {
        insertinBST(root,temp);
      }
      return root;
    }
    bool searchinBST(TreeNode<T>*root,T value) {
      if(root==nullptr) {
        return false;
      }
      if(value>root->value) {
        return searchinBST(root->right,value);
      }
      if(value<root->value) {
        return searchinBST(root->left,value);
      }
      if(value==root->value) {
        return true;
      }
    }
};
