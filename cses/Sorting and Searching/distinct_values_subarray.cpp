#include <bits/stdc++.h>

using namespace std;

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

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	unordered_set<int, custom_hash> S;
	long long ans = 0;

	for (int l = 0, r = 0; r < n; ++r) {
		while (S.count(a[r])) {
			S.erase(a[l]);
			++l;
		}
		S.insert(a[r]);
		ans += r - l + 1;
	}

	printf("%lld\n", ans);

	return 0;
}