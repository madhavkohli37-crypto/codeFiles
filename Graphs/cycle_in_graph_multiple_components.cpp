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
// we are creating undirected/directed unweighted graph
template<typename T>
class Graph{
private:
map<T,list<T>>mp;
public:
void addEdge(T x,T y,bool direction) {
    mp[x].push_back(y);
    if(!direction) {
        mp[y].push_back(x);
    }
    return;
}
void print() {
    for(pair<int,list<int>> it:mp) {
        cout<<(it).first<<" --> ";
        for(int x:(it).second) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
// The code is valid for single and multiple components
bool dfs_helper(T value,T parent,map<T,bool>&visited) {
    visited[value]=true;
    for(int x:mp[value]) {
        if(!visited[x]) {
            bool smallcycle=dfs_helper(x,value,visited);
        if(smallcycle) {
            return true;
        }
        }
        else if(x!=parent) {
            return true;
        }   
    }
    return false;
}
bool dfs() {
    bool ans=false;
    for(pair<int,list<int>>p:mp) {
        map<T,bool>visited;
        ans=(ans or dfs_helper(p.first,-1,visited));
    }
    return ans;
}
};
int32_t main() {
    int n,m;
    cin>>n>>m;
    bool direction=0;
    Graph<int> gh;
    for(int i=0;i<m;i++) {
        int x,y; 
        cin>>x>>y;
        gh.addEdge(x,y,direction);
    }
    gh.print();
    cout<<endl;
    cout<<gh.dfs();
}

   
