#include <bits/stdc++.h>

using namespace std;

#define N 2501

int dis[N][N][2];
queue<pair<int, int>> Q;

void BFS(
		const vector<vector<int>>& adj,
		int d[N][2],
		const int s) {
	for (int i = 1; i < N; i++) {
		d[i][0] = d[i][1] = INT_MAX;
	}

	d[s][0] = 0;
	Q.push({s, 0});

	while (!Q.empty()) {
		const auto [i, d_i] = Q.front();
		Q.pop();

		const int new_d = d_i + 1;
		for (const int j : adj[i]) {
			if (new_d < d[j][new_d & 1]) {
				d[j][new_d & 1] = new_d;
				Q.push({j, new_d});
			}
		}
	}
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		BFS(adj, dis[i], i);
	}

	while (q--) {
		int i, j, x;
		scanf("%d%d%d", &i, &j, &x);
		printf("%s\n", dis[i][j][x & 1] <= x ? "YES" : "NO");
	}

	return 0;
}