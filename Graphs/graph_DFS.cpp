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
map<T,bool>visited;
queue<T>q;
map<T,list<T>>mp;
map<T,T>distance;
public:
void addEdge(T x,T y,bool direction) {
    mp[x].push_back(y);
    if(!direction) {
        mp[y].push_back(x);
    }
    return;
}
// print the adjancey list 
void print() {
    for(pair<int,list<int>> it:mp) {
        cout<<(it).first<<" --> ";
        for(int x:(it).second) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void bfs(T value) {
    visited[value]=true;
    this->q.push(value);
    
    while(!q.empty()) {
        T z=q.front();
        q.pop();
        for(int x:mp[z]) {
            if(!visited[x]) {
                q.push(x);
            }
            visited[x]=true;
        }
        cout<<z<<" ";
    }
}
void bfs_shortest_distance(T value) {
    if(!mp.count(value)) {
        return ;
    }
    distance[value]=0;
    q.push(value);
    while(!q.empty()) {
        value=q.front();
        q.pop();
        for(T x:mp[value]) {
            if(!distance.count(x)) {
                q.push(x);
                distance[x]=distance[value]+1;
                cout<<x<<" --> "<<distance[x]<<endl;
            }
        }
    }
    return;
}
void dfs_helper(T value) { 
    if(!visited[value]) {
        cout<<value<<" ";
    }
    else {
        return;
    }
    visited[value]=true;
    for(T x:mp[value]) {
        dfs_helper(x);
    }
    return;
}
void dfs(T value) {
    dfs_helper(value);
    return;
}
};
int32_t main() {
    int m,n;
    cin>>m>>n;
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
    gh.dfs(1);
}

   
