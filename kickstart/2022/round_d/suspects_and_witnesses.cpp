#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void SccDFS(
		const vector<vector<int>>& adj,
		vector<int>& S,
		vector<bool>& on_stack,
		vector<int>& start_time,
		vector<int>& low_link,
		vector<int>& scc_leader,
		vector<int>& topological_order,
		int& timer,
		const int i) {
	start_time[i] = ++timer;
	low_link[i] = start_time[i];

	S.push_back(i);
	on_stack[i] = true;

	for (const int j : adj[i]) {
		if (start_time[j] == 0) {
			SccDFS(adj, S, on_stack, start_time, low_link, scc_leader, topological_order, timer, j);
			low_link[i] = min(low_link[i], low_link[j]);
			continue;
		}

		if (!on_stack[j]) {
			continue;
		}

		low_link[i] = min(low_link[i], start_time[j]);
	}

	topological_order.push_back(i);

	if (low_link[i] != start_time[i]) {
		return;
	}

	for (int w = -1; w != i; S.pop_back()) {
		w = S.back();
		on_stack[w] = false;
		scc_leader[w] = i;
	}
}

int Solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[j].push_back(i);
	}

	int timer = 0;
	vector<int> S, start_time(n + 1), low_link(n + 1), scc_leader(n + 1), topological_order;
	vector<bool> on_stack(n + 1);

	for (int i = 1; i <= n; ++i) {
		if (start_time[i] != 0) {
			continue;
		}
		SccDFS(adj, S, on_stack, start_time, low_link, scc_leader, topological_order, timer, i);
	}

	vector<unordered_set<int>> scc_adj(n + 1), dp(n + 1);
	vector<bool> is_safe(n + 1);

	for (const int i : topological_order) {
		const int si = scc_leader[i];
		auto& dpi = dp[si];

		if (dpi.size() <= k) {
			dpi.insert(i);
		}

		auto& scc_adj_si = scc_adj[si];
		for (const int j : adj[i]) {
			const int sj = scc_leader[j];
			if (sj == si) {
				continue;
			}
			scc_adj_si.insert(sj);
		}

		if (i != si) {
			continue;
		}

		is_safe[i] = dpi.size() > k;

		if (is_safe[i]) {
			continue;
		}

		for (const int sj : scc_adj_si) {
			if (is_safe[sj]) {
				is_safe[i] = true;
				break;
			}
		}

		if (is_safe[i]) {
			continue;
		}

		for (const int sj : scc_adj_si) {
			if (is_safe[i]) {
				break;
			}

			for (const int j : dp[sj]) {
				dpi.insert(j);
				if (dpi.size() > k) {
					is_safe[i] = true;
					break;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += is_safe[scc_leader[i]];
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}