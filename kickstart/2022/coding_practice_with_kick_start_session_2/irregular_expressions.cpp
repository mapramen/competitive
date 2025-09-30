#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsVowel(const char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int GetNextVowelIndex(const string& s, int i) {
	const int n = s.size();
	for (++i; i < n && !IsVowel(s[i]); ++i);
	return i;
}

bool Solve() {
	string s;
	cin >> s;

	const int n = s.size();
	for (int x = GetNextVowelIndex(s, -1); x < n; x = GetNextVowelIndex(s, x)) {
		const int y = GetNextVowelIndex(s, x);
		for (int z = GetNextVowelIndex(s, GetNextVowelIndex(s, y)); z + (y - x) < n; z = GetNextVowelIndex(s, z)) {
			int i = x, j = z;
			for (; i <= y && s[i] == s[j]; ++i, ++j);
			if (i > y) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve() ? "Spell!" : "Nothing.");
	}
	return 0;
}