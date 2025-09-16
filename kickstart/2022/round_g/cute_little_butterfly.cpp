#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100000

struct NodeData {
	ll lazy_update;
	ll ans;
};

NodeData dp_left[4 * N], dp_right[4 * N];

void Reset(NodeData T[], const int k, const int l, const int r) {
	T[k].lazy_update = LLONG_MIN;
	T[k].ans = LLONG_MIN;

	if (l == r) {
		return;
	}

	const int mid = (l + r) / 2;
	Reset(T, 2 * k + 1, l, mid);
	Reset(T, 2 * k + 2, mid + 1, r);
}

void Reset() {
	Reset(dp_left, 0, 0, N);
	Reset(dp_right, 0, 0, N);
}

void UpdateNode(NodeData T[], const int k, const ll x) {
	if (x <= T[k].lazy_update) {
		return;
	}

	T[k].lazy_update = x;
	T[k].ans = max(T[k].ans, x);
}

void LazyUpdateChildren(NodeData T[], const int k) {
	UpdateNode(T, 2 * k + 1, T[k].lazy_update);
	UpdateNode(T, 2 * k + 2, T[k].lazy_update);
}

void Combine(NodeData T[], const int k) {
	T[k].ans = max(T[2 * k + 1].ans, T[2 * k + 2].ans);
}

void Update(NodeData T[], const int k, const int l, const int r, const int ql, const int qr, const ll x) {
	if (r < l || qr < l || r < ql) {
		return;
	}

	if (ql <= l && r <= qr) {
		UpdateNode(T, k, x);
		return;
	}

	LazyUpdateChildren(T, k);

	const int mid = (l + r) / 2;
	Update(T, 2 * k + 1, l, mid, ql, qr, x);
	Update(T, 2 * k + 2, mid + 1, r, ql, qr, x);
	Combine(T, k);
}

void Update(NodeData T[], const int ql, const int qr, const ll x) {
	return Update(T, 0, 0, N, ql, qr, x);
}

ll Query(NodeData T[], const int k, const int l, const int r, const int i) {
	if (r < l || i < l || r < i) {
		return LLONG_MIN;
	}

	if (i == l && r == i) {
		return T[k].ans;
	}

	LazyUpdateChildren(T, k);

	const int mid = (l + r) / 2;
	return i <= mid ? Query(T, 2 * k + 1, l, mid, i) : Query(T, 2 * k + 2, mid + 1, r, i);
}

ll Query(NodeData T[], const int i) {
	return Query(T, 0, 0, N, i);
}

ll Solve() {
	int n, e;
	scanf("%d%d", &n, &e);

	map<int, vector<pair<int, int>>> y_to_flowers;
	while (n--) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		y_to_flowers[-y].push_back({x, c});
	}

	Reset();
	Update(dp_right, 0, N, 0);

	for (auto [_, v] : y_to_flowers) {
		Update(dp_left, 0, N, Query(dp_right, N) - e);
		Update(dp_right, 0, N, Query(dp_left, 0) - e);

		sort(v.begin(), v.end());
		for (const auto [x, c] : v) {
			Update(dp_right, x, N, Query(dp_right, x) + c);
		}

		reverse(v.begin(), v.end());
		for (const auto [x, c] : v) {
			Update(dp_left, 0, x, Query(dp_left, x) + c);
		}
	}

	return max(Query(dp_left, 0), Query(dp_right, N));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}