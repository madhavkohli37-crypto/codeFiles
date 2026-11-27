#include <iostream>
using namespace std;
template <typename T> class MapNode {
public:
    MapNode<int>* next;
    string key;
    int val;
    MapNode() {
        this->key = "";
        this->val = 0;
        this->next = nullptr;
    }
    MapNode(string key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
    }
};
class HashMap {
public:
    MapNode<int>** table;
    int cs;
    int ts;
    HashMap() {
        cs = 0;
        ts = 10;
        table = new MapNode<int>*[ts];
        for (int i = 0; i < ts; i++) {
            table[i] = nullptr;
        }
    }
    void rehashing() {
        MapNode<int>** oldtable = table;
        ts *= 2;
        table = new MapNode<int>*[ts];
        for (int i = 0; i < ts; i++) {
            table[i] = nullptr;
        }
        for (int i = 0; i < cs; i++) {
            MapNode<int>* head = oldtable[i];
            while (head != nullptr) {
                insert(head->key, head->val);
                head = head->next;
            }
        }
        delete[] oldtable;
        return;
    }
    int hashfunction(string key) {
        int sum = 0;
        int multiplier = 1;
        for (int i = 0; i < key.size(); i++) {
            sum =
                (((sum % ts) + ((key[i] % ts) * (multiplier % ts)) % ts)) % ts;
            multiplier = ((multiplier % ts) * (131 % ts)) % ts;
        }
        return sum;
    }
    void insert(string key, int val) {
        int index = hashfunction(key);
        MapNode<int>* node = new MapNode<int>(key, val);
        node->next = table[index];
        table[index] = node;
        cs++;
        if (((cs / ts) * 1.0) >= 0.7) {
            rehashing();
        }
        return;
    }
    void print() {
        for (int i = 0; i < ts; i++) {
            cout << i << " ) . ";
            MapNode<int>* head = table[i];
            while (head != nullptr) {
                cout << head->key << " " << head->val << " --> ";
                head = head->next;
            }
            cout << "NULL\n";
        }
        return;
    }
    int& operator[](string x) {
        int index = hashfunction(x);
        MapNode<int>* head = table[index];
        while (head != nullptr) {
            if (head->key == x) {
                return head->val;
            }
            head = head->next;
        }
        insert(x, int());
        index = hashfunction(x);
        head = table[index];
        while (head != nullptr) {
            if (head->key == x) {
                return head->val;
            }
        }
        return table[index]->val;
    }
};

int main() {
    HashMap mp;
    mp.insert("Madhav", 2);
    mp.print();
    mp["Bhoomi"] = 5;
    cout << mp["Bhoomi"] << endl;
    cout << "Hello, World!";
    return 0;
}
