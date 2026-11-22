#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MapNode{
    public:
    MapNode<T>* next;
    string key;
    T val;
    MapNode() {
        this->next=nullptr;
        this->key="";
        this->val=0;
    }
    MapNode(string key,T val) {
        this->key=key;
        this->val=val;
    }
};
template<typename T>
class HashMap{
    public:
    int cs,ts;
    MapNode<T>**table;
    HashMap() {
        cs=0,ts=10;
        table=new MapNode<T>*[ts];
        for(int i=0;i<ts;i++) {
            table[i]=nullptr;
        }
    }
    private:
    void rehashing() {
        MapNode<T>**oldtable=table;
        ts*=2;
        table=new MapNode<T>*[ts];
        for(int i=0;i<ts;i++) {
            table[i]=nullptr;
        }
        for(int i=0;i<cs;i++) {
            MapNode<T>*head=oldtable[i];
            while(head!=nullptr) {
                insert(head->key,head->val);
                head=head->next;
            }
        }
        return;
    }
    int hashfunction(string key) {
        int sum=0;
        int multiplier=1;
        for(int i=0;i<key.size();i++) {
            sum = ((sum % ts) + ((multiplier % ts) * (key[i] % ts)) % ts) % ts;
            multiplier = ((multiplier % ts) * (131 % ts)) % ts;
        }
        return sum;
    }
    public:
    void insert(string key,int val) {
        int index=hashfunction(key);
        MapNode<T>* head=new MapNode(key,val);
        head->next=table[index];
        table[index]=head;
        cs++;
        if(((cs/ts)*(1.0))>=0.7) {
            rehashing();
        }
        return;
    }
    void print() {
        for(int i=0;i<ts;i++) {
            cout<<i<<"). ";
            MapNode<T>*head=table[i];
            while(head!=nullptr) {
                cout<<head->key<<" "<<head->val<<" --> ";
                head=head->next;
            }
            cout<<"NULL\n";
        }
        return;
    }
    T& operator [] (string  x) {
        int index=hashfunction(x);
        MapNode<T>* head=table[index];
        while(head!=nullptr) {
            if(head->key==x) {
                return head->val;
            }
            head=head->next;
        }
        insert(x,T());
        index=hashfunction(x);
        head=table[index];
        while(head!=nullptr) {
            if(head->key==x) {
                return head->val;
            }
            head=head->next;
        }
         return table[index]->val;
    }
};
int main() {
    HashMap<int>mp;
    mp.insert("Madhav",0);
    mp.insert("Bhoomi",1);
    mp.print();
    mp["bhoomi"]=5;
    cout<<mp["bhoomi"];
    return 0;
}
