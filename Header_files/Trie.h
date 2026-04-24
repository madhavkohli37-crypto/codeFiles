#include"TrieNode.h"
class Trie{
  private:
  TrieNode*root;
  public:
  Trie() {
  this->root=new TrieNode();
  }
  TrieNode*temp;
  void insert(string s) {
    temp=this->root;
    for(char ch:s) {
      if((temp->mp.count(ch))==0) {
        TrieNode*n=new TrieNode(ch);
        temp->mp[ch]=n;
      }
      temp=temp->mp[ch];
    }
    temp->check=true;
  }
  bool search(string str) {
    temp=this->root;
    for(char ch:str) {
      if(temp->mp.count(ch)) {
        temp=temp->mp[ch];
      }
      else {
        return false;
      }
    }
    return temp->check;
  }
  
};
