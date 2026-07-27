#include<iostream>
#include<vector>
using namespace std;
namespace my{
template <typename T>
class vector{
public:
T arr[5];
vector() {
    for(int i=0;i<5;i++) {
        arr[i]='0';
    }
}
vector(T x) {
    for(int i=0;i<5;i++) {
        arr[i]=x;
    }
}
};
}
int main() {
    my::vector<int>v(52);
    std::cout<<v.arr[2]<<std::endl;
    int x=5;
    std::cout<<x<<std::endl;
}
