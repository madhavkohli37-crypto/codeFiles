#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
#include<list>
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
};
int32_t main() {
    int m,n;
    cin>>m>>n;
    bool direction=1;
    Graph<int> gh;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        gh.addEdge(x,y,direction);
    }
    gh.print();
}

   
