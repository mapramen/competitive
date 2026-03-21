#include <bits/stdc++.h>

using namespace std;

#define N 5001

vector<pair<int, int>> adj[N];
long long p[N];

bool DFS(const int i, const long long expected) {
	if (p[i] != LLONG_MIN) {
		return p[i] == expected;
	}

	p[i] = expected;

	for (const auto& [j, w] : adj[i]) {
		if (!DFS(j, expected + w)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	while (m--) {
		int l, r, s;
		scanf("%d%d%d", &l, &r, &s);
		adj[l - 1].push_back({r, s});
		adj[r].push_back({l - 1, -s});
	}

	for (int i = 0; i <= n; i++) {
		p[i] = LLONG_MIN;
	}

	for (int i = 0; i <= n; ++i) {
		if (p[i] != LLONG_MIN) {
			continue;
		}

		if (!DFS(i, 0)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		printf("%lld ", p[i] - p[i - 1]);
	}
	printf("\n");

	return 0;
}