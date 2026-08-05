// #include<iostream>
// #include<thread>
// #include<mutex>
// using namespace std;
// mutex m;
// void inc(int &x) {
//      thread t execution started
//     m.lock();
//    x++;
//    m.unlock();
//     manual locking and unlocking is one way of doing the task but it is good as long as the function 
//  reaches the unlock()
//  suppose we encounter an exception and function does 
//  throw "error";
//  then the value x might be locked foreover because we never unlock it
//     return;
// }
// int main() {
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
//     int x;
//     cin>>x;
//     thread t1(increment(x));
//     thread t2(increment(x));
//     inc(x);

// } better way of doing it is
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void increment()
{
    lock_guard<mutex> lock(m);

    // The constructor of lock_guard automatically
    // calls m.lock().

    counter++;

    // When the function ends,
    // 'lock' goes out of scope.
    // Its destructor automatically calls m.unlock().
}

int main()
{
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << counter;
} 
/*
This is the key difference

The mutex does not stop the whole thread.

It only stops other threads from entering the critical section:
while join() stops the entire thread.
THIS MUTEX FUNCTION IS USED TO PREVENT THE RACE CONDITION.
A race condition occurs when two or more threads access the same shared resource concurrently,
and at least one of them modifies it, without proper synchronization. Because the execution order of the threads is unpredictable, the final result 
can vary from run to run.
*/