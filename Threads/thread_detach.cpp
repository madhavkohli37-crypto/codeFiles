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
    t.detach();//detached that thread so that the main() thread does not waits for the thread t to finish
    // that means thread t can main thread can work independently 
    // if main() thread finished first then thread t will continue working and if thread t finsihed first 
    // main thread continues working
    // if we do not use detach or join then there could be an exception error because there could be an active
    // thread that is still working
    // thread t finished execution
    cout<<"World\n";
    return 0;
    // main thread execution finished
//note --> By default join() should be the best choice because it waits for the complete execution of the thread t.
if the main() thread finishes it's task the entire program is terminated and all the leftover threads are killed irrespective of their task is over or not.
/*
#include <iostream>
#include <thread>
using namespace std;

void work()
{
    for(int i = 1; i <= 100; i++)
    {
        cout << i << endl;
    }
}

int main()
{
    thread t(work);

    t.detach();
    cout<<"Waiting...\n";

    return 0;
}
Here the output could be Waiting... 1
2
3
or Waiting... 1
2
or 1 
2 
Waiting..
or simply just Waiting...
it depends only upon when does main() thread ends.
Hence detach() is not a safe option and join() is safe.

*/

}