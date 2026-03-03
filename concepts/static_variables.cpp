/*
if we do not have the chance to do any of the two i.e we can neither send tmp as a parameter
nor we can use temp globally 
we can then use the concept of static variables
*/
#include <iostream>
using namespace std;
// int temp=0;
void F(int n/*,int temp*/) {
  static int temp=0;//static variables are initialised only once 
  // if they are initialised in the same function ever again the compiler does'nt re-initiate
  // them it just overwrites the updations in the same memory block
  // like here we can see that we F function tries to initialise temp with 0 in every 
  // recursion call but since it is static it just updates in the initially created temp
  // int temp=0;//this will print temp as 0 only because every time temp is initialised with 0
  if(n==11) {
    cout<<temp;//to fix this we can use temp as a global variable or we can pass it as a parameter
    return;
  }
  cout<<n<<" ";
  temp++;
  F(n+1/*,temp+1*/);
  return;
}
int main() {
  F(1/*,0*/);
}