#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());

pair<int, vector<int>> GetColoring(const vector<vector<int>>& adj, const vector<int>& p) {
	const int n = adj.size();
	vector<int> color(n);

	for (const int i : p) {
		int used_mask = 0;
		for (const int j : adj[i]) {
			used_mask |= 1 << color[j];
		}
		color[i] = __builtin_ctz(~used_mask);
	}
	return {*max_element(color.begin(), color.end()) + 1, color};
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int>> adj(n);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		--i, --j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	vector<int> p(n);
	iota(p.begin(), p.end(), 0);

	pair<int, vector<int>> best = GetColoring(adj, p);
	for (int iter = 0; iter < 1000; ++iter) {
		shuffle(p.begin(), p.end(), rnd);
		best = min(best, GetColoring(adj, p));
	}

	printf("%d\n", best.first);
	for (const int c : best.second) {
		printf("%d ", c + 1);
	}
	printf("\n");

	return 0;
}