#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	unordered_map<int, int, custom_hash> latest_index;
	vector<int> dp(n + 1);
	dp[0] = 1;

	for (int r = 1, l = 0, sum = 0; r <= n; ++r) {
		sum = (sum + dp[r - 1]) % MOD;

		const auto it = latest_index.find(a[r]);
		if (it != latest_index.end()) {
			for (; l < it->second; ++l) {
				sum = (sum + MOD - dp[l]) % MOD;
			}
		}
		latest_index[a[r]] = r;

		dp[r] = sum;
	}

	printf("%d\n", dp[n]);

	return 0;
}