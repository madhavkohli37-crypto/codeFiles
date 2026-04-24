#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
class TrieNode{
  public:
  char data;
  bool check;
  map<char,TrieNode*>mp;
  TrieNode() {
    this->data='\0';
    check=false;
  }
  TrieNode(char data) {
    this->data=data;
    this->check=false;
  }
};
