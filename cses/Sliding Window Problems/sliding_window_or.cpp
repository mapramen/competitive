#include <bits/stdc++.h>

using namespace std;

#define B 30

int GenerateNext(const int a, const int b, const int c, const int x) {
	return (1ll * a * x + b) % c;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);

	vector<pair<int, int>> S;
	S.push_back({x, 0});

	int ans = k == 1 ? x : 0;

	for (int i = 1; i < n; ++i) {
		x = GenerateNext(a, b, c, x);
		S.push_back({x, i});

		if (i < k - 1) {
			continue;
		}

		int or_sum = 0;
		for (int j = S.size() - 1; j > -1; --j) {
			if (S[j].second <= i - k || (S[j].first & or_sum) == S[j].first) {
				S[j].first = 0;
				continue;
			}
			or_sum |= S[j].first;
		}

		for (int p = 0, q = 0; q < S.size(); ++q) {
			if (S[q].first == 0) {
				continue;
			}

			while (p < q && S[p].first != 0) {
				++p;
			}

			if (p == q) {
				continue;
			}

			swap(S[p], S[q]);
		}

		while (!S.empty() && S.back().first == 0) {
			S.pop_back();
		}

		ans ^= or_sum;
	}

	printf("%d\n", ans);

	return 0;
}