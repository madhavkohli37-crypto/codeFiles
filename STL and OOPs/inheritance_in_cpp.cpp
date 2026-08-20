#include <iostream>
using namespace std;
class Animal{
public :
void eat() {
    cout<<"Yes\n";
}
};
// derived class
class dog :public Animal{
public:
void bark() {
    cout<<"Bhao Bhao\n";
}
};
int main() 
{
    dog g;
    g.eat();
    g.bark();
    cout << "Hello, World!";
    return 0;
}