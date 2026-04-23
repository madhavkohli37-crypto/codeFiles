// there are various functions like erase in set and map too(ordered as well as unordered)
#include<set>
#include<map>
#include<iostream>
using namespace std;
int main() {
  set<int>s;
  map<int>mp;
  for(int i=0;i<10;i++) {
    mp.insert(i);
    s.insert(i);
  }
  mp.erase(mp.begin(),mp.begin()+3);//o(log(n))+distance
  s.erase(s.begin(),s.begin()+3);//o(log(n))+distance
  // you can also remove by value 
  mp.erase(5);
  s.erase(5);
}
