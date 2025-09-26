#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

struct tuple_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(tuple<int, int, char> t) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

		const auto [x, y, d] = t;
		return splitmix64((1ll * x * 100000 + y) * 1000 + d);
	}
};

pii GetMove(const char d) {
	switch (d) {
		case 'N':
			return {-1, 0};
		case 'E':
			return {0, 1};
		case 'W':
			return {0, -1};
		case 'S':
			return {1, 0};
	}
	assert(false);
}

void Populate(unordered_map<tuple<int, int, char>, pii, tuple_hash>& table, const int x, const int y) {
	table[{x, y, 'N'}] = {x - 1, y};
	table[{x, y, 'E'}] = {x, y + 1};
	table[{x, y, 'W'}] = {x, y - 1};
	table[{x, y, 'S'}] = {x + 1, y};
}

pii GetNext(unordered_map<tuple<int, int, char>, pii, tuple_hash>& table, const char d, const int x, const int y) {
	const auto it = table.find({x, y, d});
	if (it == table.end()) {
		return {x, y};
	}

	const auto [nx, ny] = it->second;
	return it->second = GetNext(table, d, nx, ny);
}

pii Solve() {
	int n, r, c, x, y;
	scanf("%d%d%d%d%d", &n, &r, &c, &x, &y);

	string s;
	cin >> s;

	unordered_map<tuple<int, int, char>, pii, tuple_hash> table;

	for (const char d : s) {
		Populate(table, x, y);
		tie(x, y) = GetNext(table, d, x, y);
	}

	return {x, y};
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		const auto [x, y] = Solve();
		printf("Case #%d: %d %d\n", k, x, y);
	}
	return 0;
}