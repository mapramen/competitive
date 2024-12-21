#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_LEVELS 2

// +---+---+---+
// | 7 | 8 | 9 |
// +---+---+---+
// | 4 | 5 | 6 |
// +---+---+---+
// | 1 | 2 | 3 |
// +---+---+---+
//     | 0 | A |
//     +---+---+

const vector<vector<char>> numeric_keypad = {
		{'7', '8', '9'},
		{'4', '5', '6'},
		{'1', '2', '3'},
		{' ', '0', 'A'}};

//     +---+---+
//     | ^ | A |
// +---+---+---+
// | < | v | > |
// +---+---+---+
const vector<vector<char>> directional_keypad = {
		{' ', '^', 'A'},
		{'<', 'v', '>'}};

const unordered_map<char, pii> directions = {
		{'^', {-1, 0}},
		{'v', {1, 0}},
		{'<', {0, -1}},
		{'>', {0, 1}}};

const vector<char> moves = {'<', 'v', '>', '^'};

map<pair<char, char>, vector<string>> previous_level_strings;
map<pair<int, string>, ll> shortest_length;

pii FindCoordinates(const vector<vector<char>>& keypad, const char key) {
	for (int i = 0; i < keypad.size(); i++) {
		for (int j = 0; j < keypad[i].size(); j++) {
			if (keypad[i][j] == key) {
				return {i, j};
			}
		}
	}
	assert(false);
}

vector<string> GetPreviosLevelStrings(const vector<vector<char>>& keypad, const char previous_char, const char current_char) {
	auto it = previous_level_strings.find({previous_char, current_char});
	if (it != previous_level_strings.end()) {
		return it->second;
	}

	const auto [sx, sy] = FindCoordinates(keypad, previous_char);
	const auto [ex, ey] = FindCoordinates(keypad, current_char);

	vector<string> ans;

	queue<tuple<string, int, int>> Q;
	Q.push({"", sx, sy});

	while (!Q.empty()) {
		auto [s, x, y] = Q.front();
		Q.pop();

		if (x == ex && y == ey) {
			if (ans.empty() || ans.back().size() == s.size()) {
				ans.push_back(s);
			}
			continue;
		}

		if (!ans.empty() && ans.back().size() <= s.size()) {
			continue;
		}

		for (char move : moves) {
			const auto [dx, dy] = directions.at(move);
			int nx = x + dx;
			int ny = y + dy;

			if (nx < 0 || nx >= keypad.size() || ny < 0 || ny >= keypad.front().size() || keypad[nx][ny] == ' ') {
				continue;
			}

			Q.push({s + move, nx, ny});
		}
	}

	return previous_level_strings[{previous_char, current_char}] = ans;
}

ll CalculateShortestSequenceLength(const int level, const string& s) {
	if (level == 0) {
		// printf("level: %d, s: %s, ans: %d\n", level, s.c_str(), s.size());
		return s.size();
	}

	auto it = shortest_length.find({level, s});
	if (it != shortest_length.end()) {
		return it->second;
	}

	const auto& keypad = level == NUMBER_OF_LEVELS + 1 ? numeric_keypad : directional_keypad;

	ll ans = 0;

	char previous_char = 'A';
	for (char current_char : s) {
		ll ansx = LLONG_MAX;

		for (string t : GetPreviosLevelStrings(keypad, previous_char, current_char)) {
			t.push_back('A');
			ansx = min(ansx, CalculateShortestSequenceLength(level - 1, t));
		}

		ans += ansx;
		previous_char = current_char;
	}

	// printf("level: %d, s: %s, ans: %lld\n", level, s.c_str(), ans);

	return shortest_length[{level, s}] = ans;
}

ll CalculateComplexity(const string s) {
	ll len = CalculateShortestSequenceLength(NUMBER_OF_LEVELS + 1, s);
	ll numeric_part = stoll(string(s.begin(), s.end() - 1));
	// cout << s << " " << len << " " << numeric_part << endl;
	return len * numeric_part;
}

int main() {
	ll ans = 0;
	for (string line; getline(cin, line);) {
		ans += CalculateComplexity(line);
	}
	cout << ans << endl;
	return 0;
}