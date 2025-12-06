#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadLines() {
	vector<string> v;
	for (string s; getline(cin, s); v.push_back(s));
	return v;
}

int main() {
	const auto& lines = ReadLines();
	const int n = lines.size();
	const int m = lines.back().size();

	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		const char op = lines.back()[i];
		ll result = op == '+' ? 0 : 1;

		int j = i + 1;
		for (; j < m && isspace(lines.back()[j]); ++j);
		if (j != m) {
			--j;
		}

		for (; i < j; ++i) {
			int x = 0;
			for (int l = 0; l < n - 1; ++l) {
				if (isspace(lines[l][i])) {
					continue;
				}
				x = 10 * x + (lines[l][i] - '0');
			}
			result = op == '+' ? result + x : result * x;
		}

		ans += result;
	}

	cout << ans << '\n';

	return 0;
}