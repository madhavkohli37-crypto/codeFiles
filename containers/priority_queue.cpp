#include<iostream>
#include<queue>
using namespace std;
int main() {
    priority_queue<int,vector<int>,greater<int>>pq;//min heap
    priority_queue<int>pq1;//max_heap(by default)
    int i=0;
    while(i!=10) {
        pq.push(i);
        pq1.push(i);
        i++;
    }
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    while(!pq1.empty()) {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;
}
// OUTPUT :-
// 0 1 2 3 4 5 6 7 8 9 
// 9 8 7 6 5 4 3 2 1 0 
