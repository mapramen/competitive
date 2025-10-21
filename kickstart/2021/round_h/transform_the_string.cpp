#include <bits/stdc++.h>

using namespace std;

#define B 26

int Dist(const char c, const char d) {
	const int k = abs(c - d);
	return min(k, B - k);
}

int Solve() {
	string s, f;
	cin >> s >> f;

	const int m = f.size();

	vector<int> d(B, B);
	for (int k = 0, j = 0; k < B; ++k) {
		for (; j < m && (f[j] - 'a') < k; ++j);
		d[k] = min(Dist('a' + k, f[j % m]), Dist('a' + k, f[(m + j - 1) % m]));
	}

	int ans = 0;
	for (const char c : s) {
		ans += d[c - 'a'];
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}