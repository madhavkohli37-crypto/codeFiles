#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define int long long
// template<typename T> we now assume that each element in the DSU is an integer
class DSU {
    public:
    unordered_map<char,int>rank;
    unordered_map<char,char>superparent;
    int totalcomponents;
    char findS(char node) {
        if(superparent[node]=='A') {
            return node;
        }
        return superparent[node]=findS(superparent[node]);
    }
    void unionS(char x,char y) {
        char S1=findS(x);
        char S2=findS(y);
        if(S1!=S2) {
            if(rank[S1]>rank[S2]) {
                superparent[S2]=S1;
                rank[S1]+=rank[S2];
            }
            else {
                superparent[S1]=S2;
                rank[S2]+=rank[S1];
            }
            totalcomponents--;
        }
    }
};
int32_t main() {
    int n;
    cin>>n;
    DSU d;
    vector<string>v;
    unordered_set<char>s;
    for(int i=0;i<n;i++) {
        string str;
        cin>>str;
        v.push_back(str);
        for(char ch:str) {
            d.rank[ch]=1;
            d.superparent[ch]='A';
            s.insert(ch);
        }
    }
    d.totalcomponents=s.size();
    for(string str:v) {
        if(str.length()>1) {
            for(int i=1;i<str.length();i++) {
                d.unionS(str[0],str[i]);
            }
        }
    }
    cout<<d.totalcomponents<<endl;

    return 0;
}

   
