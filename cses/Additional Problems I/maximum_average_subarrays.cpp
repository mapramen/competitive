#include <bits/stdc++.h>

using namespace std;

__int128_t Cross(const pair<__int128_t, __int128_t>& p, const pair<__int128_t, __int128_t>& q) {
	return 1ll * p.first * q.second - 1ll * p.second * q.first;
}

__int128_t Area2(const pair<__int128_t, __int128_t>& a, const pair<__int128_t, __int128_t>& b, const pair<__int128_t, __int128_t>& c) {
	return Cross(a, b) + Cross(b, c) + Cross(c, a);
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<__int128_t, __int128_t>> bottom_hull;
	bottom_hull.push_back({0, 0});

	for (__int128_t i = 1, sum = 0; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		sum += x;

		while (bottom_hull.size() > 1 && Area2(bottom_hull[bottom_hull.size() - 2], bottom_hull.back(), {i, sum}) <= 0) {
			bottom_hull.pop_back();
		}

		printf("%d ", (int)(i - bottom_hull.back().first));
		bottom_hull.push_back({i, sum});
	}
	printf("\n");

	return 0;
}