#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ParseInts(string s, char delimiter) {
	vector<int> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delimiter)) {
		result.push_back(stoi(item));
	}

	return result;
}

unordered_map<int, vector<int>> ReadOrderRules() {
	unordered_map<int, vector<int>> order_rules;

	for (string s; getline(cin, s);) {
		if (s.empty()) {
			break;
		}

		vector<int> order_rule = ParseInts(s, '|');
		order_rules[order_rule[0]].push_back(order_rule[1]);
	}

	return order_rules;
}

vector<int> ParseUpdateLine(string s) {
	return ParseInts(s, ',');
}

bool IsUpdateValid(unordered_map<int, vector<int>>& order_rules, vector<int>& update) {
	unordered_set<int> visited;

	for (int x : update) {
		for (int y : order_rules[x]) {
			if (visited.find(y) != visited.end()) {
				return false;
			}
		}
		visited.insert(x);
	}

	return true;
}

int GetMiddleElement(vector<int>& update) {
	return update[update.size() / 2];
}

int main() {
	unordered_map<int, vector<int>> order_rules = ReadOrderRules();

	ll ans = 0;
	for (string s; getline(cin, s);) {
		vector<int> update = ParseUpdateLine(s);
		if (IsUpdateValid(order_rules, update)) {
			ans += GetMiddleElement(update);
		}
	}

	printf("%lld\n", ans);

	return 0;
}