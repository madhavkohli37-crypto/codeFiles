#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
#include<list>
using namespace std;
#define int long long
template<typename T>
// this is insertion in an undirected graph

class Graph{
private:
map<T,list<T>>mp;
public:
void addEdge(T x,T y,bool direction) {
    mp[x].push_back(y);
    if(!direction) {
        mp[y].push_back(x);
    }
}
};
int32_t main() {
    int n,m;
    cin>>n>>m;
    bool direction=0;//since undirected grpah we assume that direction is 0
    Graph<int> gh;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        gh.addEdge(x,y,direction);
    }
}

   
