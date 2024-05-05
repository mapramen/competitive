#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int j;
			scanf("%d", &j);
			adj[i].push_back(j);
		}
		sort(adj[i].begin(), adj[i].end());
	}

	vector<int> d(n + 1), parent(n + 1, -1);
	queue<int> Q;

	d[1] = 0, parent[1] = 0;
	Q.push(1);

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		for (int j : adj[i]) {
			if (parent[j] != -1) {
				continue;
			}
			d[j] = d[i] + 1;
			parent[j] = i;
			Q.push(j);
		}
	}

	if (d[n] == 0) {
		return {};
	}

	vector<int> ans;
	for (int i = n; i != 0; i = parent[i]) {
		ans.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	ans.pop_back();
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<int> ans = Solve();
		if (ans.empty()) {
			printf("-1\n");
			continue;
		}

		printf("%lu\n", ans.size());
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n\n");
	}
	return 0;
}