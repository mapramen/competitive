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

int main() {
	vector<pll> ranges = ReadIdRanges();
	sort(ranges.begin(), ranges.end());

	const int n = ranges.size();

	ll ans = 0;
	for (int i = 0; i < n;) {
		auto [l, r] = ranges[i];
		for (; i < n && ranges[i].first <= r; ++i) {
			r = max(r, ranges[i].second);
		}
		ans += (r - l + 1);
	}

	cout << ans << '\n';

	return 0;
}