/*if you try to submit this code on CSES it will show runtime
error beacuse in line no. 36 we have initiated the frequency
array with size maxi+1 which is out of bound because the
maximum size of an array can be 1e8 but the size of maxi can be
upto the limits of long long hence stack overflow occurs
the logic providid by sir in class is also not getting
submitted hence you need the concept of maps to submit it.
This is the most optimised code till now without the
use of map.*/
#include <iostream>
#include<climits>
using namespace std;
#define int long long
int32_t main() {

	int n, k;
	cin >> n >> k;
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
	for (int i = 0; i <= maxi; i++) {
		if (frequency[i] >= 1) {
			cout << i << "-->" << frequency[i] << endl;
		}
	}
	int count = frequency[k];
	int f;
	for (int i = 1; i <= n; i++) {
		if (((prefix[i] - k) > 0) && (frequency[((prefix[i]) - k)] > 0)) {
			f = frequency[((prefix[i]) - k)];
			count += (f * (f - 1) / 2) + 1;
		}
	}
	cout << count;
}