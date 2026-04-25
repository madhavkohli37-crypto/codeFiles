#include<iostream>
#include<map>
using namespace std;
class TrieNode{
  public:
  char data;
  bool check;
  int size;
  map<char,TrieNode*>mp;
  TrieNode() {
    size=0;
    this->data='\0';
    check=false;
  }
  TrieNode(char data) {
    size=0;
    this->data=data;
    this->check=false;
  }
};
