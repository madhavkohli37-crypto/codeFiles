#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
#include<list>
#include<utility>
#include<queue>
#include<vector>
using namespace std;
#define int long long
// template<typename T> we now assume that each element in the DSU is an integer
class DSU{
    private:
    vector<int>superparent;
    vector<int>rank;
    int totalcomponents;
    public:
    DSU(int n) {
        superparent.resize(n+1,-1);
        rank.resize(n+1,1);
        totalcomponents=n;
    }
    void print() {
        cout<<totalcomponents<<endl;
        for(int i=1;i<=rank.size()-1;i++) {
            if(superparent[i]==-1) {
                cout<<"---------\n";
            }
            cout<<i<<" -> "<<rank[i]<<" "<<superparent[i]<<endl;
        }
    }
    int findS(int node) {
        if(superparent[node]==-1) {
            return node;
        }
        // path compression (DP)
        return superparent[node]=findS(superparent[node]);
    }
    void unionS(int x,int y) {
        // union by rank
        int S1=findS(x);
        int S2=findS(y);
        if(S1!=S2) {
            if(rank[S1]<rank[S2]) {
                superparent[S1]=S2;
                rank[S2]+=rank[S1];
            }
            else {
                superparent[S2]=S1;
                rank[S1]+=rank[S2];
            }
            totalcomponents--;
        }
    }
};
int32_t main() {
    int n,m;
    cin>>n>>m;
    DSU d(n);
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        d.unionS(x,y);
    }
    d.print();
    return 0;
}

   
