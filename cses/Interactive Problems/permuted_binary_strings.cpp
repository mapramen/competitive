#include <bits/stdc++.h>

using namespace std;

string Query(const int n, const int i) {
	cout << "? ";
	for (int x = 1; x <= n; ++x) {
		const int b = (x & (1 << i)) != 0;
		cout << b;
	}
	cout << '\n';
	fflush(stdout);

	string s;
	cin >> s;
	return s;
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

	vector<int> p(n);
	for (int k = __lg(n); k > -1; --k) {
		const auto s = Query(n, k);

		for (int i = 0; i < n; ++i) {
			p[i] += (s[i] == '1') * (1 << k);
		}
	}

	PrintAns(p);

	return 0;
}