#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<string>> ReadInputs() {
	vector<vector<string>> S;

	while (true) {
		vector<string> s;

		for (string line; getline(cin, line) && line != "";) {
			s.push_back(line);
		}

		if (s.empty()) {
			break;
		}

		S.push_back(s);
	}

	return S;
}

bool IsLock(const vector<string>& s) {
	const int m = s.front().size();

	for (int y = 0; y < m; ++y) {
		if (s.front()[y] != '#') {
			return false;
		}
	}

	for (int y = 0; y < m; ++y) {
		if (s.back()[y] != '.') {
			return false;
		}
	}

	return true;
}

bool IsKey(const vector<string>& s) {
	const int m = s.front().size();

	for (int y = 0; y < m; ++y) {
		if (s.front()[y] != '.') {
			return false;
		}
	}

	for (int y = 0; y < m; ++y) {
		if (s.back()[y] != '#') {
			return false;
		}
	}

	return true;
}

vector<int> ConvertLockToInts(const vector<string>& s) {
	const int m = s.front().size();

	vector<int> a;
	for (int y = 0; y < m; ++y) {
		int cnt = 0;
		for (int x = 1; s[x][y] == '#'; ++x) {
			++cnt;
		}
		a.push_back(cnt);
	}
	return a;
}

vector<int> ConvertKeyToInts(const vector<string>& s) {
	const int n = s.size(), m = s.front().size();

	vector<int> a;
	for (int y = 0; y < m; ++y) {
		int cnt = 0;
		for (int x = n - 2; s[x][y] == '#'; --x) {
			++cnt;
		}
		a.push_back(cnt);
	}
	return a;
}

bool IsLockAndKeyMatch(const int n, const vector<int>& lock, const vector<int>& key) {
	const int m = lock.size();
	for (int i = 0; i < m; ++i) {
		if (lock[i] + key[i] > n - 2) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<vector<string>> S = ReadInputs();
	// printf("S.size() = %lu\n", S.size());

	// for (const auto& s : S) {
	// 	for (const auto& line : s) {
	// 		printf("%s\n", line.c_str());
	// 	}
	// 	printf("\n");
	// }

	vector<vector<int>> locks, keys;
	for (const auto& s : S) {
		if (IsLock(s)) {
			locks.push_back(ConvertLockToInts(s));
			continue;
		}

		if (IsKey(s)) {
			keys.push_back(ConvertKeyToInts(s));
			continue;
		}

		assert(false);
	}

	// printf("locks.size() = %lu\n", locks.size());
	// printf("keys.size() = %lu\n", keys.size());

	const int n = S.front().size();
	int ans = 0;
	for (const auto& lock : locks) {
		for (const auto& key : keys) {
			ans += IsLockAndKeyMatch(n, lock, key);

			// for (int x : lock) {
			// 	printf("%d,", x);
			// }
			// printf(" ");

			// for (int x : key) {
			// 	printf("%d,", x);
			// }
			// printf(" %d\n", IsLockAndKeyMatch(n, lock, key));
		}
	}

	printf("%d\n", ans);

	return 0;
}