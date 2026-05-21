#include <bits/stdc++.h>
using namespace std;
int n=0;
set<string>st;
void permute(string s,int i) {
    if(i==s.size()) {
        st.insert(s);
        return;
    }
    for(int j=i;j<s.size();j++) {
        swap(s[i],s[j]);
        permute(s,i+1);
        swap(s[i],s[j]);
    }
    return;
}
int main() {
    string s;
    cin >> s;
    permute(s,0);
    cout<<st.size()<<endl;
    for(string s:st) {
        cout<<s<<endl;
    }
}
