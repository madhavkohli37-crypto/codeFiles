#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
inline void delay(int time) {//since it could be used multiple times make it inline
    this_thread::sleep_for(chrono::seconds(time));
}
void hello() {
    // thread t execution started
    cout<<"Hello"<<endl;
    delay(3);
    cout<<"Slept for 3 seconds\n";
    return;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    thread t(hello);
    t.join();
    cout<<"Awake\n";
    return 0;

}