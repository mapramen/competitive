#include <bits/stdc++.h>

using namespace std;

void update(vector<int>& T, const int k, const int l, const int r, const int i, const int x) {
	if (r < l || i < l || r < i) {
		return;
	}

	if (i == l && r == i) {
		T[k] = x;
		return;
	}

	update(T, 2 * k + 1, l, (l + r) / 2, i, x);
	update(T, 2 * k + 2, (l + r) / 2 + 1, r, i, x);
	T[k] = max(T[2 * k + 1], T[2 * k + 2]);
}

int query(vector<int>& T, const int k, const int l, const int r, const int ql, const int qr) {
	if (r < l || qr < l || r < ql) {
		return 0;
	}

	if (ql <= l && r <= qr) {
		return T[k];
	}

	return max(
			query(T, 2 * k + 1, l, (l + r) / 2, ql, qr),
			query(T, 2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
}

void add(map<int, set<int>>& indices_map, vector<int>& T, const int n, const int i, const int x) {
	auto it = indices_map.find(x);
	if (it == indices_map.end()) {
		it = indices_map.insert({x, set<int>()}).first;
	}

	auto& S = it->second;
	const auto st = S.insert(i).first;

	const int prv_index = *S.begin() == i ? 0 : *prev(st);
	const int nxt_index = *S.rbegin() == i ? n + 1 : *next(st);

	update(T, 0, 1, n, nxt_index, i);
	update(T, 0, 1, n, i, prv_index);
}

void remove(map<int, set<int>>& indices_map, vector<int>& T, const int n, const int i, const int x) {
	auto& S = indices_map.find(x)->second;
	const auto st = S.find(i);

	const int prv_index = *S.begin() == i ? 0 : *prev(st);
	const int nxt_index = *S.rbegin() == i ? n + 1 : *next(st);
	S.erase(st);

	update(T, 0, 1, n, nxt_index, prv_index);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<int> a(n + 1);
	map<int, set<int>> indices_map;
	vector<int> T(4 * n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		add(indices_map, T, n, i, a[i]);
	}

	while (q--) {
		int t;
		scanf("%d", &t);

		if (t == 1) {
			int i, x;
			scanf("%d%d", &i, &x);

			remove(indices_map, T, n, i, a[i]);
			a[i] = x;
			add(indices_map, T, n, i, a[i]);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%s\n", query(T, 0, 1, n, l, r) < l ? "YES" : "NO");
		}
	}

	return 0;
}