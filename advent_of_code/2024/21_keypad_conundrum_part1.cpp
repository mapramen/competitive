#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_LEVELS 3

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

const vector<char> moves = {'<', 'v', '>', '^', 'A'};

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

void CheckAndPush(queue<pair<vector<pii>, int>>& Q, map<pair<vector<pii>, int>, int>& dist, const vector<pii>& state, const int i, const int d) {
	auto it = dist.find({state, i});
	if (it != dist.end()) {
		return;
	}

	dist[{state, i}] = d;
	Q.push({state, i});
}

int CalculateShortestSequenceLength(const string s) {
	map<pair<vector<pii>, int>, int> dist;
	queue<pair<vector<pii>, int>> Q;

	vector<pii> initial_state(NUMBER_OF_LEVELS);
	initial_state[0] = FindCoordinates(numeric_keypad, 'A');
	for (int level = 1; level < NUMBER_OF_LEVELS; level++) {
		initial_state[level] = FindCoordinates(directional_keypad, 'A');
	}

	CheckAndPush(Q, dist, initial_state, 0, 0);

	while (!Q.empty()) {
		const auto [state, i] = Q.front();
		const int d = dist[{state, i}];
		Q.pop();

		if (i == s.size()) {
			return d;
		}

		for (const char move : moves) {
			bool is_move_valid = true;
			char previous_level_move = move;
			vector<pii> new_state(state);
			int ni = i;

			for (int level = NUMBER_OF_LEVELS - 1; level > -1 && previous_level_move != ' '; --level) {
				const auto [x, y] = new_state[level];
				const auto& keypad = level == 0 ? numeric_keypad : directional_keypad;

				if (previous_level_move == 'A') {
					previous_level_move = keypad[x][y];
					continue;
				}

				const auto [dx, dy] = directions.at(previous_level_move);
				const int nx = x + dx, ny = y + dy;

				if (nx < 0 || nx >= keypad.size() || ny < 0 || ny >= keypad.front().size() || keypad[nx][ny] == ' ') {
					is_move_valid = false;
				} else {
					new_state[level] = {nx, ny};
				}

				previous_level_move = ' ';
			}

			if (!is_move_valid || (previous_level_move != ' ' && s[ni] != previous_level_move)) {
				continue;
			}

			if (s[ni] == previous_level_move) {
				++ni;
			}

			CheckAndPush(Q, dist, new_state, ni, d + 1);
		}
	}

	assert(false);
}

ll CalculateComplexity(const string s) {
	int len = CalculateShortestSequenceLength(s);
	int numeric_part = stoll(string(s.begin(), s.end() - 1));
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