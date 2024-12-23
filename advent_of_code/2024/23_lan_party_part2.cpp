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

void PrintLanParty(vector<string>& lan_party) {
	sort(lan_party.begin(), lan_party.end());
	for (int i = 0; i < lan_party.size(); ++i) {
		if (i > 0) {
			cout << ',';
		}
		cout << lan_party[i];
	}
	cout << endl;
}

void LanPartyDFS(const unordered_map<string, unordered_set<string>>& adj, vector<string>& lan_party, const vector<string>& candidates, unordered_set<string>& visited, const string& u) {
	visited.insert(u);

	if (visited.size() > lan_party.size()) {
		lan_party = vector<string>(visited.begin(), visited.end());
		// PrintLanParty(lan_party);
	}

	vector<string> new_candidates;
	for (const string& v : candidates) {
		if (v <= u || visited.count(v) || adj.at(u).count(v) == 0) {
			continue;
		}
		new_candidates.push_back(v);
	}

	for (const string& v : new_candidates) {
		LanPartyDFS(adj, lan_party, new_candidates, visited, v);
	}

	visited.erase(u);
}

int main() {
	unordered_map<string, unordered_set<string>> adj = ReadInput();

	vector<string> lan_party;
	unordered_set<string> visited;
	for (const auto& [u, neigbours] : adj) {
		const vector<string> candidates(neigbours.begin(), neigbours.end());
		LanPartyDFS(adj, lan_party, candidates, visited, u);
	}

	PrintLanParty(lan_party);

	return 0;
}