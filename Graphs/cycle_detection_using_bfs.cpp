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
map<T,bool>visited;
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
bool cycle_detection_using_bfs(T node) {
    queue<T>q;
    map<T,T>parent;
    q.push(node);
    visited[node]=true;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(int z:mp[x]) {
            if(!visited[z]) {
                q.push(z);
                parent[z]=x;
                visited[z]=true;
            }
            else {
                if(parent[x]!=z) {
                    return true;
                }
            }
        }
    }
    return false;
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
    cout<<gh.cycle_detection_using_bfs(1);
}

   
