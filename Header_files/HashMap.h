#include "MapNode.h"
template<typename T>
class HashMap{
    public:
    MapNode<T>**table;
    int cs;
    int ts;
    HashMap() {
        table=new MapNode<T>*[10];
        cs=0;
        ts=10;
        for(int i=0;i<7;i++) {
            table[i]=NULL;
        }
    }
    void rehashing() {
        MapNode<T>**oldtable=table;
        table=new MapNode<T>*[2*ts];
        ts=2*ts;
        cs=0;
        for(int i=0;i<ts;i++) {
            table[i]=NULL;
        }
        MapNode<T>*head;
        for(int i=0;i<ts/2;i++) {
            head=oldtable[i];
            while(head!=NULL) {
                insert(head->key,head->value);
                head=head->next;
            }
        }
        delete[] oldtable;
        return;
    }
    int hashfunction(string s) {
        int multiplier=1;
        int sum=0;
        for(int i=0;i<s.size();i++) {
            sum+=(((s[i]%ts)*(multiplier%ts))%ts);
            multiplier=(((131%ts)*(multiplier%ts))%ts);
        }
        return (sum%ts);
    }
    void insert(string key,T value) {
        int index=hashfunction(key);
        /*
        At this index we are storing this key-value pair in the hash table
        The hash-table will have a pointer which is pointing to the address of the
        List of those Pair which are to be inserted at that index.
        Yani index i of the hash table mein eek address hoga jo ki sabhi unn 
        key-value pairs ki list ka head hoga jo index i pe aani chaiye
        */
        MapNode<T>*m=new MapNode(key,value);//now we need to follow insert at head
        m->next=table[index];
        table[index]=m; 
        cs++;
        if(((cs/ts)*1.0)>=0.7) {
        rehashing();
    }
    }
    void print() {
      MapNode<T>*head;
      for(int i=0;i<ts;i++) {
        head=table[i];
        cout<<i<<" ). ";
        while(head!=NULL) {
          cout<<head->key<<" "<<head->value<<" --> ";
          head=head->next;
        }
        cout<<"NULL";
        cout<<endl;
      }
      return;
    }

};
