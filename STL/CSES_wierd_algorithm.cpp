#include <iostream>
using namespace std;
#define int long long
int32_t main() {

  int n;

  cin >> n;
  cout << n << " ";
  while (true) {
    if (n == 2 or n == 1) {
      break;
    }
    if (n % 2 == 1) {
      n *= 3;
      n++;
      cout << n << " ";
    }
    else {
      n /= 2;
      cout << n << " ";
    }
  }
  if (n != 1) {
    cout << 1;
  }


}