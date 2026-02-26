#include <iostream>
#include<climits>
using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int prefix[ n + 1] {0};
	prefix[1] = a[1] ;
	// cout << prefix[1] << " ";
	for (int i = 2; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
		// cout << prefix[i] << " ";
	}
	// cout << endl;
	int maxi = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (prefix[i] > maxi) {
			maxi = prefix[i];
		}
	}
	// cout << maxi << endl;
	int frequency[maxi + 1] {0};
	for (int i = 1; i <= n; i++) {
		int element = prefix[i];
		frequency[element]++;
	}
	// for (int i = 0; i <= maxi; i++) {
	// 	if (frequency[i] >= 1) {
	// 		cout << i << "-->" << frequency[i] << endl;
	// 	}
	// }
	int count = frequency[0];
	int f;
	for (int i = 0; i <= maxi ; i++) {
		f = frequency[i];
		if (frequency[i] > 0) {
			count += (f * (f - 1) / 2);
		}
	}
	cout << "N.o. of subarrays having sum 0 --> " << count;




}