#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void SlidingWindowKnapsack(vector<int>& dp, const int k, const int cnt) {
	if (cnt == 0) {
		return;
	}

	const int n = dp.size() - 1;
	for (int r = 0; r < k; ++r) {
		deque<pair<int, int>> Q;
		for (int i = r, x = 0; i <= n; i += k, ++x) {
			const int val = dp[i] - x;
			while (!Q.empty() && Q.back().first >= val) {
				Q.pop_back();
			}
			Q.push_back({val, x});

			while (!Q.empty() && (x - Q.front().second) > cnt) {
				Q.pop_front();
			}

			dp[i] = x + Q.front().first;
		}
	}
}

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}

	vector<int> cnt(n + 1);

	for (int i = 1; i <= n; ++i) {
		if (p[i] == 0) {
			continue;
		}

		int k = 0;
		for (int j = i; p[j] != 0; ++k) {
			const int nj = p[j];
			p[j] = 0;
			j = nj;
		}

		++cnt[k];
	}

	vector<int> dp(n + 1, n);
	dp[0] = 0;

	for (int k = 1; k <= n; ++k) {
		SlidingWindowKnapsack(dp, k, cnt[k]);
	}

	for (int i = 1; i <= n; ++i) {
		--dp[i];
	}

	for (int i = n, x = n; i > 0; --i) {
		x = min(x, dp[i]);
		dp[i] = min(dp[i], 1 + x);
	}

	return vector<int>(dp.begin() + 1, dp.end());
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: ", k);
		for (const int x : Solve()) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}