#include"Trie.h"
#include<string>
using namespace std;
int main() {
  Trie t;
  string s;
  while(cin>>s) {
    t.insert(s);
  }
  cout<<t.search("Madha")<<endl;
  cout<<t.SUP("Maya")<<endl;
}
