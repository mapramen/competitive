#include <bits/stdc++.h>

using namespace std;

struct node {
	long long sum = 0;
	long long ans = 0;
	long long prefix_ans = 0;
	long long suffix_ans = 0;
};

node combine(const node& a, const node& b) {
	return {
			a.sum + b.sum,
			max(0ll, max(a.suffix_ans + b.prefix_ans, max(a.ans, b.ans))),
			max(a.prefix_ans, a.sum + b.prefix_ans),
			max(a.suffix_ans + b.sum, b.suffix_ans)};
}

void initialize(const vector<int>& a, vector<node>& T, const int k, const int l, const int r) {
	if (l == r) {
		const int x = a[l];
		T[k] = {x, max(0, x), max(0, x), max(0, x)};
		return;
	}

	initialize(a, T, 2 * k + 1, l, (l + r) / 2);
	initialize(a, T, 2 * k + 2, (l + r) / 2 + 1, r);
	T[k] = combine(T[2 * k + 1], T[2 * k + 2]);
}

node query(const vector<node>& T, const int k, const int l, const int r, const int ql, const int qr) {
	if (r < l || qr < l || r < ql) {
		return {0, 0, 0, 0};
	}

	if (ql <= l && r <= qr) {
		return T[k];
	}

	return combine(
			query(T, 2 * k + 1, l, (l + r) / 2, ql, qr),
			query(T, 2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<node> T(4 * n);
	initialize(a, T, 0, 0, n - 1);

	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		const auto [_, ans, __, ___] = query(T, 0, 0, n - 1, l - 1, r - 1);
		printf("%lld\n", ans);
	}

	return 0;
}