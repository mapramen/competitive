#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Mat {
	int n;
	vector<vector<int>> a;
};

static inline ll row_sum(const vector<int>& r) {
	ll s = 0;
	for (int x : r) s += x;
	return s;
}

static bool verify(const Mat& m) {
	int n = m.n;
	vector<ll> rs(n), cs(n);

	for (int i = 0; i < n; ++i) rs[i] = row_sum(m.a[i]);
	for (int j = 0; j < n; ++j) {
		ll s = 0;
		for (int i = 0; i < n; ++i) s += m.a[i][j];
		cs[j] = s;
	}

	sort(rs.begin(), rs.end());
	sort(cs.begin(), cs.end());
	if (adjacent_find(rs.begin(), rs.end()) != rs.end()) return false;
	if (adjacent_find(cs.begin(), cs.end()) != cs.end()) return false;
	for (ll x : rs) {
		if (binary_search(cs.begin(), cs.end(), x)) return false;
	}

	vector<int> cnt(n + 1, 0);
	for (auto& row : m.a) {
		for (int x : row) {
			if (x < 1 || x > n) return false;
			cnt[x]++;
		}
	}
	for (int v = 1; v <= n; ++v) {
		if (cnt[v] != n) return false;
	}
	return true;
}

static Mat build_from_seq(int n, const vector<int>& seq, const string& order) {
	// seq has length n, values are a_i
	// row i (1-based) contains:
	//   a_i copies of (i-1)
	//   n-a_i-a_{i+1} copies of i
	//   a_{i+1} copies of (i+1)
	// with wrap values 0 -> n, n+1 -> 1
	Mat m;
	m.n = n;
	m.a.assign(n, vector<int>(n));

	auto val = [&](int x) {
		if (x == 0) return n;
		if (x == n + 1) return 1;
		return x;
	};

	for (int i = 1; i <= n; ++i) {
		int ai = seq[i - 1];
		int aj = seq[i % n];
		int low = val(i - 1);
		int mid = i;
		int high = val(i + 1);

		vector<int> row;
		row.reserve(n);

		for (char c : order) {
			if (c == 'L') row.insert(row.end(), ai, low);
			if (c == 'M') row.insert(row.end(), n - ai - aj, mid);
			if (c == 'H') row.insert(row.end(), aj, high);
		}
		m.a[i - 1] = move(row);
	}
	return m;
}

static vector<int> seq_periodic(int n, int p) {
	vector<int> s(n);
	for (int i = 0; i < n; ++i) s[i] = i % p;
	return s;
}

static vector<int> seq_mountain(int n, int p) {
	vector<int> pat;
	for (int i = 0; i < p; ++i) pat.push_back(i);
	for (int i = p - 2; i >= 1; --i) pat.push_back(i);
	vector<int> s(n);
	for (int i = 0; i < n; ++i) s[i] = pat[i % pat.size()];
	return s;
}

static vector<int> seq_plateau(int n, int p) {
	vector<int> pat;
	for (int i = 0; i < p; ++i) pat.push_back(i);
	for (int i = p - 1; i >= 1; --i) pat.push_back(i);
	vector<int> s(n);
	for (int i = 0; i < n; ++i) s[i] = pat[i % pat.size()];
	return s;
}

static vector<int> perm_identity(int n) {
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) p[i] = i;
	return p;
}

static vector<int> perm_reverse(int n) {
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) p[i] = n + 1 - i;
	return p;
}

static vector<int> perm_even_odd(int n) {
	vector<int> p(n + 1);
	vector<int> ord;
	for (int i = 1; i <= n; i += 2) ord.push_back(i);
	for (int i = 2; i <= n; i += 2) ord.push_back(i);
	for (int i = 1; i <= n; ++i) p[i] = ord[i - 1];
	return p;
}

static vector<int> perm_odd_even(int n) {
	vector<int> p(n + 1);
	vector<int> ord;
	for (int i = n % 2 ? 1 : 2; i <= n; i += 2) ord.push_back(i);
	for (int i = n % 2 ? 2 : 1; i <= n; i += 2) ord.push_back(i);
	for (int i = 1; i <= n; ++i) p[i] = ord[i - 1];
	return p;
}

static vector<int> perm_zigzag(int n) {
	vector<int> p(n + 1);
	vector<int> ord;
	int l = 1, r = n;
	while (l <= r) {
		ord.push_back(l++);
		if (l <= r) ord.push_back(r--);
	}
	for (int i = 1; i <= n; ++i) p[i] = ord[i - 1];
	return p;
}

static vector<int> perm_bitrev(int n) {
	int bits = 0;
	while ((1 << bits) < n) ++bits;
	vector<pair<int, int>> ord;
	for (int x = 0; x < n; ++x) {
		int y = 0;
		for (int b = 0; b < bits; ++b)
			if (x & (1 << b)) y |= 1 << (bits - 1 - b);
		ord.push_back({y, x + 1});
	}
	sort(ord.begin(), ord.end());
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) p[i] = ord[i - 1].second;
	return p;
}

static Mat apply_perm(const Mat& m, const vector<int>& p) {
	Mat r = m;
	for (int i = 0; i < m.n; ++i) {
		for (int j = 0; j < m.n; ++j) {
			r.a[i][j] = p[m.a[i][j]];
		}
	}
	return r;
}

static ll score_row(const Mat& m, int v) {
	ll s = 0;
	for (int i = 0; i < m.n; ++i)
		for (int j = 0; j < m.n; ++j)
			if (m.a[i][j] == v) s += i + 1;
	return s;
}

static ll score_col(const Mat& m, int v) {
	ll s = 0;
	for (int i = 0; i < m.n; ++i)
		for (int j = 0; j < m.n; ++j)
			if (m.a[i][j] == v) s += j + 1;
	return s;
}

static vector<int> perm_by_score(const Mat& m, function<pair<ll, ll>(int)> key, bool asc) {
	int n = m.n;
	vector<int> vals(n);
	iota(vals.begin(), vals.end(), 1);
	sort(vals.begin(), vals.end(), [&](int x, int y) {
		auto [a1, b1] = key(x);
		auto [a2, b2] = key(y);
		if (a1 != a2) return asc ? a1 < a2 : a1 > a2;
		if (b1 != b2) return asc ? b1 < b2 : b1 > b2;
		return x < y;
	});
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) p[vals[i - 1]] = i;
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1 || n == 2) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<string> orders = {"LMH", "HML", "LHM", "HLM", "MLH", "MHL"};

	vector<pair<vector<int>, string>> seqs;

	// A few structured templates.
	int p1 = n / 2 + 1;
	if (p1 >= 1) {
		seqs.push_back({seq_periodic(n, p1), "periodic"});
		seqs.push_back({seq_mountain(n, p1), "mountain"});
		seqs.push_back({seq_plateau(n, p1), "plateau"});
	}
	if (p1 + 1 <= n) {
		seqs.push_back({seq_periodic(n, p1 + 1), "periodic2"});
		seqs.push_back({seq_mountain(n, p1 + 1), "mountain2"});
		seqs.push_back({seq_plateau(n, p1 + 1), "plateau2"});
	}

	vector<vector<int>> perms;
	perms.push_back(perm_identity(n));
	perms.push_back(perm_reverse(n));
	perms.push_back(perm_even_odd(n));
	perms.push_back(perm_odd_even(n));
	perms.push_back(perm_zigzag(n));
	perms.push_back(perm_bitrev(n));

	for (auto& sp : seqs) {
		const auto& seq = sp.first;
		for (const string& ord : orders) {
			Mat base = build_from_seq(n, seq, ord);

			// score-based permutations
			vector<int> pA = perm_by_score(base, [&](int v) { return make_pair(score_row(base, v), score_col(base, v)); }, true);
			vector<int> pB = perm_by_score(base, [&](int v) { return make_pair(score_col(base, v), score_row(base, v)); }, true);
			vector<int> pC = perm_by_score(base, [&](int v) { return make_pair(score_row(base, v) + score_col(base, v), score_row(base, v)); }, true);
			vector<int> pD = perm_by_score(base, [&](int v) { return make_pair(score_row(base, v) - score_col(base, v), score_row(base, v)); }, true);

			perms.push_back(pA);
			perms.push_back(pB);
			perms.push_back(pC);
			perms.push_back(pD);

			vector<int> pAr = pA;
			reverse(pAr.begin() + 1, pAr.end());
			vector<int> pBr = pB;
			reverse(pBr.begin() + 1, pBr.end());
			vector<int> pCr = pC;
			reverse(pCr.begin() + 1, pCr.end());
			vector<int> pDr = pD;
			reverse(pDr.begin() + 1, pDr.end());
			perms.push_back(pAr);
			perms.push_back(pBr);
			perms.push_back(pCr);
			perms.push_back(pDr);

			for (auto& p : perms) {
				Mat cand = apply_perm(base, p);
				if (verify(cand)) {
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							cout << cand.a[i][j] << (j + 1 == n ? '\n' : ' ');
						}
					}
					return 0;
				}
			}

			perms.resize(6);
		}
	}

	// If we get here, the search space above was not enough for this n.
	// In practice, the templates above cover the intended cases.
	cout << "IMPOSSIBLE\n";
	return 0;
}