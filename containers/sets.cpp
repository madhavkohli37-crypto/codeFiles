#include <iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main() {
   set<int>s;
   unordered_set<int>us;
   int n;
   cin>>n;
   for(int i=0;i<n;i++) {
       int x;
       cin>>x;
       s.insert(x);
       us.insert(x);
   }
   for(set<int>::iterator it=s.begin();it!=s.end();it++) {
       cout<<(*it)<<endl;
   }
   cout<<"-------\n";
   for(int x:us) {
       cout<<x<<endl;
   }
}
