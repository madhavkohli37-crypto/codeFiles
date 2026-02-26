#include<iostream>
using namespace std;
#define int long long
int32_t main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    int points = 0;
    int a[n + 1] {0}, b[n + 1] {0};
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      if ((a[i] + a[i - 1] + b[i - 1] + b[i]) % 2 == 0) {
        points += (a[i] - a[i - 1]);
      }
      else {
        points += (a[i] - a[i - 1] - 1);
      }

    }
    if (a[n] < m) {
      points += (m - a[n]);
    }
    cout << points << endl;

  }
}