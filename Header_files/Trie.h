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
      (temp->size)++;
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
  string SUP(string str) {
    temp=root;
    string ans;
    for(char ch:str) {
      ans+=ch;
      temp=temp->mp[ch];
      if(temp==nullptr) {
        return "No Valid Unique Prefix";
      }
      if(temp->size==1) {
      return ans;
    }
    }
    return "No Valid Unique Prefix";
  }
  //Madhav
  string LongestCommonPrefix(string str,int n) {
    temp=root;
    string ans;
    for(char ch:str) {
      temp=temp->mp[ch];
     if(temp->size==n) {
       ans+=ch;
     }
     else {
       return ans;
     }
    }
    return ans;
  }
  
};
