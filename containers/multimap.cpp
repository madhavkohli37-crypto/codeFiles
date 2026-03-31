#include<iostream>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<utility>
using namespace std;
int main() {
multimap<string,int>mp;
int n;
cin>>n;
for(int i=0;i<n;i++) {
    string s;
    int x;
    cin>>s>>x;
    pair<string,int>p=make_pair(s,x);
    mp.insert(p);
}
for(multimap<string,int>::iterator it=mp.begin();it!=mp.end();it++) {
    cout<<it->first<<" "<<it->second<<endl;
}

}
