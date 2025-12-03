#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int FindLargestPossible(const string& s) {
	int ans = 0, m = 0;
	for (const char c : s) {
		const int d = c - '0';
		ans = max(ans, 10 * m + d);
		m = max(m, d);
	}
	return ans;
}

int main() {
	int ans = 0;
	for (string s; getline(cin, s);) {
		ans += FindLargestPossible(s);
	}
	cout << ans << '\n';
	return 0;
}