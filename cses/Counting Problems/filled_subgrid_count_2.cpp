#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector<int> a(n + 1);
	vector<pair<int, int>> S;
	vector<long long> cnt(k);

	for (int x = 1; x <= n; ++x) {
		S.clear();
		for (int y = 1, sum = 0; y <= n; ++y) {
			const char c = s[x - 1][y - 1];
			a[y] = 1 + (x != 1 && c == s[x - 2][y - 1] ? a[y] : 0);

			if (y != 1 && c != s[x - 1][y - 2]) {
				S.clear();
				sum = 0;
			}

			int w = 1;
			while (!S.empty() && S.back().first > a[y]) {
				sum -= 1ll * S.back().second * S.back().first;
				w += S.back().second;
				S.pop_back();
			}

			sum += 1ll * w * a[y];
			S.push_back({a[y], w});

			cnt[c - 'A'] += sum;
		}
	}

	for (const auto& ans : cnt) {
		printf("%lld\n", ans);
	}

	return 0;
}