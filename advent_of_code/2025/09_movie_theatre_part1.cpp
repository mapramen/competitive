#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> ReadInputs() {
	vector<pii> v;
	for (int x, y; scanf("%d,%d", &x, &y) != EOF; v.push_back({x, y}));
	return v;
}

int main() {
	const auto& pts = ReadInputs();

	ll ans = 0;
	for (const auto [x1, y1] : pts) {
		for (const auto [x2, y2] : pts) {
			const int dx = abs(x2 - x1 + 1), dy = abs(y2 - y1 + 1);
			ans = max(ans, 1ll * dx * dy);
		}
	}
	cout << ans << '\n';

	return 0;
}