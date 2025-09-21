#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ReadTasks() {
	int n;
	scanf("%d", &n);

	vector<int> A(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}
	return A;
}

vector<ll> ComputeDP(const int k, const vector<int>& A) {
	const int n = A.size() - 1;
	const int m = min(n, k);

	vector<ll> dp(k + 1);
	for (ll i = 0, si = 0; i <= m; ++i) {
		if (i != 0) {
			si += A[i];
		}

		for (ll j = 0, s = si, z = i; z <= m; ++j, ++z) {
			if (j != 0) {
				s += A[n - j + 1];
			}
			dp[z] = max(dp[z], s);
		}
	}

	return dp;
}

ll Solve() {
	const auto& A = ReadTasks();
	const auto& B = ReadTasks();

	int k;
	scanf("%d", &k);

	const auto& dp1 = ComputeDP(k, A);
	const auto& dp2 = ComputeDP(k, B);

	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; i + j <= k; ++j) {
			ans = max(ans, dp1[i] + dp2[j]);
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}