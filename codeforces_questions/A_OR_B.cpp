#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int f = 0; f < t; f++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int frequency[2] {0};
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				frequency[0]++;
			}
			else {
				frequency[1]++;
			}
		}

		int position_a[frequency[0]] {0};
		for (int i = 0, j = 0; i < n; i++) {
			if (s[i] == 'a') {
				position_a[j] = i;
				j++;
			}
		}
		int position_b[frequency[1]] {0};
		for (int i = 0, j = 0; i < n; i++) {
			if (s[i] == 'b') {
				position_b[j] = i;
				j++;
			}
		}
		if (frequency[0] == 0 or frequency[1] == 0) {
			cout << 0 << endl;
			continue;
		}

		/*case-1 make all a together*/
		long long steps_a = 0;
		int index_a;
		if (frequency[0] % 2 == 1) {
			index_a = position_a[(frequency[0] / 2)];
		} else {
			index_a = position_a[(frequency[0] / 2) - 1];
		}

		int m1 = index_a, m2 = index_a;

		// CORRECTED CHECK: Find the first 'b'. Is its position less than our median index?
		bool b_exists_before_median = (s.find('b') < m1);

		// CORRECTED CHECK: Find the first 'b' starting from the median index. Does it exist?
		bool b_exists_after_median = (s.find('b', m1) != string::npos);

		if (b_exists_before_median) {
			for (int i = 0; i < m1; i++) {
				if (s[i] == 'a') {
					steps_a += (m1 - 1 - i);
					m1--;
				}
			}
		}
		if (b_exists_after_median) {
			for (int i = m2 + 1; i < n; i++) {
				if (s[i] == 'a') {
					steps_a += (i - 1 - m2);
					m2++;
				}
			}
		}
		// cout << steps_a << endl;

		/*case-2 make all b together*/
		long long steps_b = 0;
		int index_b;
		if (frequency[1] % 2 == 1) {
			index_b = position_b[(frequency[1] / 2)];
		} else {
			index_b = position_b[(frequency[1] / 2) - 1];
		}

		int m3 = index_b, m4 = index_b;

		// CORRECTED CHECK: Find the first 'a'. Is its position less than our median index?
		bool a_exists_before_median = (s.find('a') < m3);

		// CORRECTED CHECK: Find the first 'a' starting from the median index. Does it exist?
		bool a_exists_after_median = (s.find('a', m3) != string::npos);

		if (a_exists_before_median) {
			for (int i = 0; i < m3; i++) {
				if (s[i] == 'b') {
					steps_b += (m3 - 1 - i);
					m3--;
				}
			}
		}
		if (a_exists_after_median) {
			for (int i = m4 + 1; i < n; i++) {
				if (s[i] == 'b') {
					steps_b += (i - 1 - m4);
					m4++;
				}
			}
		}
		cout << min(steps_a, steps_b) << endl;
	}
}