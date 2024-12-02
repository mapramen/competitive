#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

map<pair<set<pii>, set<pii>>, ll> dp;

bool IsDominated(const pii& a, const pii& b) {
	return b.first <= a.first && b.second <= a.second;
}

vector<pii> GetCandidates(const set<pii>& unvisited) {
	vector<pii> candidates;
	for (auto& p : unvisited) {
		bool is_dominated = false;
		for (auto& candidate : candidates) {
			if (IsDominated(p, candidate)) {
				is_dominated = true;
				break;
			}
		}

		if (!is_dominated) {
			candidates.push_back(p);
		}
	}
	return candidates;
}

ll DP(set<pii>& visited, set<pii>& unvisited) {
	if (unvisited.empty()) {
		return 1;
	}

	auto it = dp.find({visited, unvisited});
	if (it != dp.end()) {
		return it->second;
	}

	ll ans = 0;
	for (auto& candidate : GetCandidates(unvisited)) {
		visited.insert(candidate);
		unvisited.erase(candidate);

		ans += DP(visited, unvisited);

		visited.erase(candidate);
		unvisited.insert(candidate);
	}

	return dp[{visited, unvisited}] = ans;
}

ll Solve() {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		exit(0);
	}

	set<pii> unvisited;
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			unvisited.insert({i, j});
		}
	}

	set<pii> visited;
	return DP(visited, unvisited);
}

int main() {
	while (true) {
		printf("%lld\n", Solve());
	}
	return 0;
}