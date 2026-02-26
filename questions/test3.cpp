#include <iostream>
#include<math.h>
#include<string>
using namespace std;
class car {
public:
  int year;
  string name;
};
int main() {
  car c1;
  c1.name = "BMW";
  c1.year = 2023;
  cout << c1.name << endl << c1.year;
}