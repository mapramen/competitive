#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for (int i = 0; i < n; ++i) cin >> g[i];

	int cells = n * m;
	int V = 2 * cells;

	// For each cell, opt[id][0/1] are the two allowed colors encoded as 0,1,2.
	vector<array<int, 2>> opt(cells);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			int id = r * m + c;
			int x = g[r][c] - 'A';
			opt[id] = {(x + 1) % 3, (x + 2) % 3};
		}
	}

	vector<int> head(V, -1), rhead(V, -1);
	vector<int> to, nxt, rto, rnxt;
	to.reserve(8LL * cells + 10);
	nxt.reserve(8LL * cells + 10);
	rto.reserve(8LL * cells + 10);
	rnxt.reserve(8LL * cells + 10);

	auto addImp = [&](int u, int v) {
		to.push_back(v);
		nxt.push_back(head[u]);
		head[u] = (int)to.size() - 1;

		rto.push_back(u);
		rnxt.push_back(rhead[v]);
		rhead[v] = (int)rto.size() - 1;
	};

	auto addClause = [&](int a, int b) {
		// (a OR b)
		addImp(a ^ 1, b);
		addImp(b ^ 1, a);
	};

	auto lit = [&](int var, int val) {
		return 2 * var + val;	 // val = 0 or 1
	};

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			int u = r * m + c;

			if (r + 1 < n) {
				int v = (r + 1) * m + c;
				for (int su = 0; su < 2; ++su) {
					for (int sv = 0; sv < 2; ++sv) {
						if (opt[u][su] == opt[v][sv]) {
							// forbid (su, sv)
							addClause(lit(u, 1 - su), lit(v, 1 - sv));
						}
					}
				}
			}

			if (c + 1 < m) {
				int v = r * m + (c + 1);
				for (int su = 0; su < 2; ++su) {
					for (int sv = 0; sv < 2; ++sv) {
						if (opt[u][su] == opt[v][sv]) {
							addClause(lit(u, 1 - su), lit(v, 1 - sv));
						}
					}
				}
			}
		}
	}

	// Kosaraju, iterative
	vector<char> vis(V, 0);
	vector<int> order;
	order.reserve(V);

	for (int s = 0; s < V; ++s) {
		if (vis[s]) continue;
		vector<pair<int, int>> st;
		st.push_back({s, head[s]});
		vis[s] = 1;

		while (!st.empty()) {
			int v = st.back().first;
			int e = st.back().second;

			if (e == -1) {
				order.push_back(v);
				st.pop_back();
				continue;
			}

			st.back().second = nxt[e];
			int u = to[e];
			if (!vis[u]) {
				vis[u] = 1;
				st.push_back({u, head[u]});
			}
		}
	}

	vector<int> comp(V, -1);
	int cid = 0;

	for (int i = V - 1; i >= 0; --i) {
		int s = order[i];
		if (comp[s] != -1) continue;

		vector<int> st = {s};
		comp[s] = cid;

		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (int e = rhead[v]; e != -1; e = rnxt[e]) {
				int u = rto[e];
				if (comp[u] == -1) {
					comp[u] = cid;
					st.push_back(u);
				}
			}
		}
		++cid;
	}

	string ans(cells, 'A');
	for (int i = 0; i < cells; ++i) {
		if (comp[2 * i] == comp[2 * i + 1]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		int state = (comp[2 * i + 1] > comp[2 * i]) ? 1 : 0;
		ans[i] = char('A' + opt[i][state]);
	}

	for (int r = 0; r < n; ++r) {
		cout << ans.substr(r * m, m) << '\n';
	}

	return 0;
}