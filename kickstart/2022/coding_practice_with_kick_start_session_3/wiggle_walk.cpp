#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

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

void Insert(set<pii>& S, const int x) {
	S.insert({INT_MIN, INT_MIN});
	S.insert({INT_MAX, INT_MAX});

	int l = x, r = x;

	const auto jt = S.upper_bound({x, INT_MAX});
	const auto it = prev(jt);

	if (it->second == x - 1) {
		l = it->first;
		S.erase(it);
	}

	if (jt->first == x + 1) {
		r = jt->second;
		S.erase(jt);
	}

	S.insert({l, r});
}

void Insert(map<int, set<pii>>& x_to_ys, map<int, set<pii>>& y_to_xs, const int x, const int y) {
	Insert(x_to_ys[x], y);
	Insert(y_to_xs[y], x);
}

int Query(set<pii>& S, const int x, const int d) {
	S.insert({INT_MIN, INT_MIN});
	S.insert({INT_MAX, INT_MAX});

	const auto [l, r] = *prev(S.upper_bound({x, INT_MAX}));
	if (x < l || r < x) {
		return x;
	}

	return d == -1 ? l - 1 : r + 1;
}

pii Solve() {
	int n, r, c, x, y;
	scanf("%d%d%d%d%d", &n, &r, &c, &x, &y);

	string s;
	cin >> s;

	map<int, set<pii>> x_to_ys, y_to_xs;
	Insert(x_to_ys, y_to_xs, x, y);

	for (const char d : s) {
		const auto [dx, dy] = GetMove(d);
		if (dx != 0) {
			x = Query(y_to_xs[y], x, dx);
		} else {
			y = Query(x_to_ys[x], y, dy);
		}
		Insert(x_to_ys, y_to_xs, x, y);
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