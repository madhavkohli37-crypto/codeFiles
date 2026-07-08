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
int cycle_detection_using_bfs_distance(T node) {
    queue<T>q;
    map<T,bool>visited;
    map<T,int>distance;
    distance[node]=0;
    q.push(node);
    visited[node]=true;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(int z:mp[x]) {
            if(!visited[z]) {
                q.push(z);
                visited[z]=true;
                distance[z]=distance[x]+1;
            }
            else {
                if(distance[z]>=distance[x]) {
                    return distance[z]+distance[x]+1;
                }
            }
        }
    }
    return INT_MAX;
}
void shcl() {
    int sh=INT_MAX;
    for(pair<int,list<int>>p:mp) {
        int value=cycle_detection_using_bfs_distance(p.first);
        if(value<sh) {
            sh=value;
        }
    }
    if(sh==INT_MAX) {
        cout<<"NO CYCLE\n";
        return;
    }
    cout<<sh<<endl;
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
    // cout<<gh.cycle_detection_using_bfs_distance(1)<<endl;
    gh.shcl();
}

   
