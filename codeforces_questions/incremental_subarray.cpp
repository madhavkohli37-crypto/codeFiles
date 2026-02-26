#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    int y = 0;
    for (int i = 0; i < m - 1; i++) {
      if (a[i] < a[i + 1]) {
        y++;
      }
    }
    if (y != m - 1) {
      cout << 1 << endl;
      continue;
    }
    else if (y == m - 1) {
      cout << n + 1 - *(max_element(a, a + m)) << endl;
    }
  }
}