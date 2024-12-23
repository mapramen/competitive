#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

unordered_map<string, unordered_set<string>> ReadInput() {
	unordered_map<string, unordered_set<string>> adj;
	for (string line; getline(cin, line);) {
		const string u = line.substr(0, 2), v = line.substr(3, 2);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	return adj;
}

int main() {
	unordered_map<string, unordered_set<string>> adj = ReadInput();

	int ans = 0;
	for (const auto& [x, neighbors] : adj) {
		for (const string& y : neighbors) {
			if (y <= x) {
				continue;
			}

			for (const string& z : neighbors) {
				if (z <= y) {
					continue;
				}

				if (adj[y].count(z) && (x[0] == 't' || y[0] == 't' || z[0] == 't')) {
					// cout << x << " " << y << " " << z << endl;
					++ans;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}