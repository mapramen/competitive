#include <bits/stdc++.h>

using namespace std;

void checkAndPush(const vector<string>& S, string& ans, vector<pair<int, int>>& nxt_level, const int x, const int y) {
	if (x == S.size() || y == S.size()) {
		return;
	}

	const char till_now_next_char = ans.back();
	const char candidate = S[x][y];

	if (till_now_next_char < candidate) {
		return;
	}

	if (candidate < till_now_next_char) {
		ans.pop_back();
		ans.push_back(candidate);
		nxt_level.clear();
	}

	nxt_level.push_back({x, y});
}

int main() {
	int n;
	scanf("%d", &n);

	vector<string> S(n);
	for (string& s : S) {
		cin >> s;
	}

	string ans{'Z' + 1};
	vector<pair<int, int>> cur_level, nxt_level;
	checkAndPush(S, ans, cur_level, 0, 0);

	while (!cur_level.empty()) {
		ans.push_back('Z' + 1);

		for (const auto [x, y] : cur_level) {
			checkAndPush(S, ans, nxt_level, x, y + 1);
			checkAndPush(S, ans, nxt_level, x + 1, y);
		}

		cur_level.swap(nxt_level);
		nxt_level.clear();

		cur_level.erase(unique(cur_level.begin(), cur_level.end()), cur_level.end());
	}

	ans.pop_back();
	cout << ans << '\n';

	return 0;
}