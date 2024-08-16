#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

struct state {
	int len, link;
	map<char, int> next;
};

state st[N * 2];
int sz;

void sa_init() {
	for (int i = 0; i <= sz; ++i) {
		st[i].len = 0, st[i].link = 0;
		st[i].next.clear();
	}
	sz = 0;

	st[0].len = 0;
	st[0].link = -1;
	sz++;
}

int sa_getnext(int p, char c) {
	if (p == -1) {
		return 0;
	}

	int q = st[p].next[c];

	if (st[p].len + 1 == st[q].len) {
		return q;
	}

	int clone = sz++;

	st[clone].len = st[p].len + 1;
	st[clone].next = st[q].next;
	st[clone].link = st[q].link;

	for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
		st[p].next[c] = clone;
	}

	st[q].link = clone;
	return clone;
}

int sa_extend(int p, char c) {
	if (st[p].next.count(c)) {
		return sa_getnext(p, c);
	}

	int cur = sz++;
	st[cur].len = st[p].len + 1;

	for (; p != -1 && !st[p].next.count(c); p = st[p].link) {
		st[p].next[c] = cur;
	}

	st[cur].link = sa_getnext(p, c);
	return cur;
}

void Solve() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<string> S(n);
	for (string& s : S) {
		cin >> s;
	}

	sa_init();

	int m = 0;
	for (const string& s : S) {
		int p = 0;
		for (char c : s) {
			p = sa_extend(p, c);
		}
		m = max(m, (int)s.size());
	}

	vector<set<int>> C(sz);

	for (int k = 0; k < n; ++k) {
		int p = 0;
		for (char c : S[k]) {
			p = st[p].next[c];
			C[p].insert(k);
		}
	}

	vector<vector<int>> V(m + 1);
	for (int i = 0; i < sz; ++i) {
		V[st[i].len].push_back(i);
	}

	for (int len = m; len > 0; --len) {
		for (int i : V[len]) {
			int j = st[i].link;
			for (int k : C[i]) {
				C[j].insert(k);
			}
		}
	}

	while (q--) {
		string s;
		cin >> s;

		int p = 0;
		for (char c : s) {
			if (!st[p].next.count(c)) {
				p = -1;
				break;
			}
			p = st[p].next[c];
		}

		int ans = p == -1 ? 0 : C[p].size();
		printf("%d\n", ans);
	}
}

int main() {
	int t = 1;
	while (t--) {
		Solve();
	}
	return 0;
}