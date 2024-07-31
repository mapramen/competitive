#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GetDigit(string t) {
	int cnt = 0;
	for (char c : t) {
		cnt += (c == ' ');
	}

	if (cnt == 2) {
		return 8;
	}

	if (cnt == 5) {
		return 4;
	}

	if (cnt == 6) {
		return 7;
	}

	if (cnt == 7) {
		return 1;
	}

	if (cnt == 3) {
		if (t[4] == ' ') {
			return 0;
		}

		return 6;
	}

	if (cnt == 4) {
		if (t[7] == ' ') {
			return 9;
		}

		if (t[5] == ' ') {
			return 5;
		}

		if (t[6] == ' ') {
			return 3;
		}

		return 2;
	}

	assert(false);
}

string Solve() {
	vector<string> s(3);
	for (int i = 0; i < 3; ++i) {
		if (!getline(cin, s[i])) {
			exit(0);
		}
	}

	string ans;
	for (int i = 0; i < s[0].size(); i += 3) {
		string t = s[0].substr(i, 3) + s[1].substr(i, 3) + s[2].substr(i, 3);
		ans.push_back('0' + GetDigit(t));
	}
	return ans;
}

int main() {
	while (true) {
		printf("%s\n", Solve().c_str());
	}
	return 0;
}