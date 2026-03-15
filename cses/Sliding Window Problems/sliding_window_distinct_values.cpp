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
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	unordered_map<int, int, custom_hash> last_index;
	for (int i = 0; i < n; ++i) {
		const int x = a[i];
		last_index[x] = i;

		if (i >= k) {
			const auto it = last_index.find(a[i - k]);
			if (it->second == i - k) {
				last_index.erase(it);
			}
		}

		if (i < k - 1) {
			continue;
		}

		printf("%lu ", last_index.size());
	}
	printf("\n");

	return 0;
}