#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pair<int, char> ReadRun() {
	int x;
	string s;
	cin >> x >> s;
	return {x, s[0]};
}

int GetNextPosition(const int L, const int x, const int d, const char direction) {
	const int r = d % L;
	return direction == 'C' ? (x + r) % L : (x + L - r) % L;
}

ll Solve() {
	int n, L;
	scanf("%d%d", &L, &n);

	ll ans = 0;
	int x = 0;
	char start_line_direction;

	while (n--) {
		auto [d, current_direction] = ReadRun();

		while (d != 0) {
			if (x == 0) {
				start_line_direction = current_direction;
				ans += (d / L);
				x = GetNextPosition(L, x, d, current_direction);
				break;
			}

			if ((current_direction == 'C' && d < L - x) || (current_direction == 'A' && d < x)) {
				x = GetNextPosition(L, x, d, current_direction);
				break;
			}

			ans += (current_direction == start_line_direction);
			d -= current_direction == 'C' ? L - x : x;
			x = 0;
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}