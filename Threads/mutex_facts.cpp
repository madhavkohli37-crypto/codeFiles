#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// Imagine the mutex as the KEY to a room.
// The room contains the shared data.
//
// Whoever has the key can enter the room.
// Everyone else must wait outside until the key is returned.

int x = 0, y = 0, z = 0;
int a = 0, b = 0, c = 0;

// One mutex (one key)
mutex m;

void f1()
{
    // Thread 1 takes the key.
    lock_guard<mutex> lock(m);

    // =============================
    // Critical Section
    // Think of x, y, z as being inside
    // one shared room.
    // =============================
    for(int i = 0; i < 100000; i++)
    {
        x++;
        y++;
        z++;
    }

    // When 'lock' goes out of scope,
    // the key is automatically returned.
}

void f2()
{
    // Thread 2 also wants to enter
    // the SAME room, so it must use
    // the SAME key (same mutex).

    lock_guard<mutex> lock(m);

    // Even though these are different
    // variables (a, b, c),
    // they are protected by the same mutex.

    for(int i = 0; i < 100000; i++)
    {
        a++;
        b++;
        c++;
    }

    // Key automatically returned here.
}

int main()
{
    thread t1(f1);
    thread t2(f2);

    t1.join();
    t2.join();

    cout << x << " "
         << y << " "
         << z << endl;

    cout << a << " "
         << b << " "
         << c << endl;
}
/*
                ROOM
      -----------------------
      |  x  y  z  a  b  c   |
      -----------------------
               🔑
             Mutex m

             Thread 1 ----> 🔑 ----> ROOM

Thread 2 ----> waits outside

Thread 2 ----> 🔑 ----> ROOM

mutex m1;
mutex m2;

void f1()
{
    lock_guard<mutex> lock(m1);

    x++;
    y++;
    z++;
}

void f2()
{
    lock_guard<mutex> lock(m2);

    a++;
    b++;
    c++;
}


Now imagine

Thread 1 has Key A

↓

Enters Room

At the same time

Thread 2 has Key B

↓

Also enters Room

This means both threads are inside simultaneously.

The mutexes don't coordinate with each other because they are different objects.

When is using two mutexes correct?

If x,y,z and a,b,c are completely independent shared resources, then using two mutexes is actually better because the threads won't block each other.

Example:

Room 1                  Room 2

x y z                   a b c

Key m1                  Key m2

Thread 1 enters Room 1.

Thread 2 enters Room 2.

They work simultaneously.

This increases parallelism.
But if we want to actually protect the data then we need to use te same function in averywhere where we want to prevent it's misuse (like f1 and f2 for x);
also cout can be acted as a shared resource.
*/