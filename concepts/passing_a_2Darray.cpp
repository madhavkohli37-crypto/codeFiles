#include <iostream>
using namespace std;
void display(int*p, int n , int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << (p + m * i)[j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	// cout << n << m;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			// cout << a[i][j] << " ";
		}
		// cout << endl;
	}
	// cout << *(a[1] );
	// display(a[0], n, m);

}