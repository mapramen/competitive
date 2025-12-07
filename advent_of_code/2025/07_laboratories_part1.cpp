#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadInput() {
	vector<string> v;
	for (string s; getline(cin, s);) {
		v.push_back(s);
	}
	return v;
}

bool IsBeam(const vector<string>& S, const int x, const int y) {
	if (x < 0 || y < 0 || x >= S.size() || y >= S.front().size()) {
		return false;
	}

	return S[x][y] == 'S' || S[x][y] == '|';
}

void Print(const vector<string>& S) {
	for (const auto& s : S) {
		cout << s << '\n';
	}
	cout << '\n';
}

int main() {
	vector<string> S = ReadInput();

	const int n = S.size(), m = S.front().size();

	int ans = 0;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (IsBeam(S, x, y)) {
				continue;
			}

			if (S[x][y] == '.') {
				if (IsBeam(S, x - 1, y)) {
					S[x][y] = '|';
				}
				continue;
			}

			if (!IsBeam(S, x - 1, y)) {
				continue;
			}

			if (y != 0) {
				S[x][y - 1] = '|';
			}

			if (y != m - 1) {
				S[x][y + 1] = '|';
			}

			++ans;
		}
		// Print(S);
	}

	cout << ans << '\n';

	return 0;
}