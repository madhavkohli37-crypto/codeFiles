#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int k = 0;
class Pair {
public:
	// int index;
	int x;
	int y;
	void getter() {
		cout << x << " " << y << " " <</* index << */endl;
	}
	Pair() {

	}
};
bool compare(Pair p, Pair q) {
	return (p.y < q.y) ;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Pair a[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
		}
		sort(a, a + n, compare);
		/*for (int i = 0; i < n; i++) {
			a[i].getter();

		}*/
		int count = 1;
		int temp = a[0].y;
		int z = 1;
		while (z < n) {
			if (a[z].x >= temp) {
				count++;
				temp = a[z].y;
			}
			z++;
		}
		cout << count << endl;
	}

}