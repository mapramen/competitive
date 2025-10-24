#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
	int n, d, c, m;
	scanf("%d%d%d%d", &n, &d, &c, &m);

	string s;
	cin >> s;

	int remaining_fed_dog_cnt = accumulate(s.begin(), s.end(), 0, [](const int acc, const char a) { return acc + (a == 'D'); });
	for (const char a : s) {
		if (a == 'D') {
			if (d <= 0) {
				break;
			}
			--d;
			c = min(n, c + m);
			--remaining_fed_dog_cnt;
			continue;
		}

		if (c <= 0) {
			break;
		}
		--c;
	}

	return remaining_fed_dog_cnt == 0;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve() ? "YES" : "NO");
	}
	return 0;
}