#include <iostream>
#include<vector>
using namespace std;
class ListNode {
    public:
     int val;
     ListNode *next;
     ListNode() {
        this->val=0;
        next=nullptr;
     }
     ListNode(int x) {
        this->val=x;
        this->next=nullptr;
     }
 };
int main() 
{
    ListNode* head=new ListNode[5]{105};
    cout<<head[0].val<<endl;
}