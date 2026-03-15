#include <bits/stdc++.h>

using namespace std;

bool Query(const int i, const int j) {
	cout << "? " << i << " " << j << "\n";
	fflush(stdout);

	string s;
	cin >> s;
	return s == "YES";
}

void PrintAns(const vector<int>& ans) {
	cout << '!';
	for (const int& x : ans) {
		cout << ' ' << x;
	}
	cout << '\n';
	fflush(stdout);
}

int main() {
	int n;
	cin >> n;

	vector<int> a{1};
	for (int i = 2; i <= n; ++i) {
		int l = 0, r = i - 1;
		while (l < r) {
			const int mid = l + (r - l) / 2;
			if (Query(i, a[mid])) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		if (l == i - 1) {
			a.push_back(i);
		} else {
			a.insert(a.begin() + l, i);
		}
	}

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[a[i] - 1] = i + 1;
	}

	PrintAns(p);

	return 0;
}