#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// first sequence => non-decreasing order
		sort(a.begin(), a.end());
		bool first_checker = true;
		int first_sum = 0;
		for (int i = 0; i < n; i++) {
			first_sum += a[i];
			// check if at any point in this sequence if the 'sum' would be 0
			if (first_sum == 0) {
				// if yes, then set 'first_checker' to false and break the loop
				first_checker = false;
				break;
			}
		}
		if (first_checker) {
			// if in this sequence there are no sums of zeroes, then output this sequence (non-decreasing)
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << '\n';
			continue;
		}
		// second sequence => non-increasing order
		bool second_checker = true;
		int second_sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			second_sum += a[i];
			// check if at any point in this sequence if the 'sum' would be 0
			if (second_sum == 0) {
				// if yes, then set 'second_checker' to false and break the loop
				second_checker = false;
				break;
			}
		}
		if (second_checker) {
			// if in this sequence there are no sums of zeroes, then output this sequence (non-increasing)
			cout << "YES\n";
			for (int i = n - 1; i >= 0; i--) {
				cout << a[i] << " ";
			}
			cout << '\n';
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}
