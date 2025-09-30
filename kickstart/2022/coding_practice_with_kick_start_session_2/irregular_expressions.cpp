#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsVowel(const char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool Solve() {
	string s;
	cin >> s;

	const int n = s.size();
	for (int x = 0; x < n; ++x) {
		int cnt1 = 0;
		for (int y = x; y < n; ++y) {
			if (cnt1 >= 2) {
				int cnt2 = 0;
				for (int z = y; z + (y - x) <= n; ++z) {
					if (cnt2 != 0) {
						int i = x, j = z;
						for (; i < y && s[i] == s[j]; ++i, ++j);
						if (i == y) {
							return true;
						}
					}
					cnt2 += IsVowel(s[z]);
				}
			}
			cnt1 += IsVowel(s[y]);
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