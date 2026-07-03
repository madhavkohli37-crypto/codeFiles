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
vector<int>v;
vector<vector<int>>CC;
int count=0;
map<T,bool>visited;
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
// The code is valid for single component only
bool dfs_helper(T value,T parent) {
    visited[value]=true;
    for(int x:mp[value]) {
        if(!visited[x]) {
            bool smallcycle=dfs_helper(x,value);
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
bool dfs(T value) {
    return dfs_helper(value,-1);
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
    cout<<gh.dfs(1);
}

   
