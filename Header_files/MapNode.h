#include<iostream>
using namespace std;
template<typename T>
class MapNode{
    public:
    string key;
    T value;
    MapNode<T>*next;
    MapNode(string key,T value) {
       this->key=key;
       this->value=value;
       next=NULL;
    }
};
