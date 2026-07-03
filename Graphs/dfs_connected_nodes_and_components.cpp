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
void dfs_helper(T value) {
    if(!visited[value]) {
        v.push_back(value);
        visited[value]=true;
        for(int x:mp[value]) {
            bfs_helper(x);
        }
    }
    return;
}
void dfs(T value) {
    if(!visited[value]) {
        count++;
        bfs_helper(value);
        CC.push_back(v);
        v.clear();
    }
    return;
}
int CCC() {
    for(pair<int,list<int>>p:mp) {
         dfs(p.first);
    }
    return count;
}
void printCC() {
    for(vector<int> w:CC) {
        for(int x:w) {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
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
    cout<<endl;
    cout<<gh.CCC()<<endl;
    gh.printCC();
}

   
