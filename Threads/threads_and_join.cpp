#include<bits/stdc++.h>
using namespace std;
void hello() {
    // thread t execution started
    cout<<"Hello";
    return;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    thread t(hello);//created a thread
    t.join();//joined that thread so that the main() thread waits for the thread t to finish
    // thread t finished execution
    cout<<"World\n";
    return 0;
    // main thread execution finished

}