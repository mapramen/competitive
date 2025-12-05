#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pll> ReadIdRanges() {
	vector<pll> v;
	for (string s; getline(cin, s) && !s.empty();) {
		const auto split_index = s.find('-');
		v.push_back({stoll(string(s, 0, split_index)), stoll(string(s, split_index + 1))});
	}
	return v;
}

bool IsInRange(const pll& range, const ll x) {
	const auto [l, r] = range;
	return l <= x && x <= r;
}

bool IsInRanges(const vector<pll>& ranges, const ll x) {
	for (const auto& range : ranges) {
		if (IsInRange(range, x)) {
			return true;
		}
	}
	return false;
}

int main() {
	const auto& fresh_id_ranges = ReadIdRanges();

	int ans = 0;
	for (ll x; cin >> x;) {
		if (IsInRanges(fresh_id_ranges, x)) {
			++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}