#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pll> ReadIdRanges() {
	string s;
	cin >> s;

	vector<pll> v;
	for (size_t pos_start = 0; pos_start < s.size();) {
		const size_t pos_id_split = s.find('-', pos_start);
		size_t pos_end = s.find(',', pos_id_split);

		if (pos_end == string::npos) {
			pos_end = s.size();
		}

		v.push_back({stoll(s.substr(pos_start, pos_id_split - pos_start)), stoll(s.substr(pos_id_split + 1, pos_end - pos_id_split))});
		pos_start = pos_end + 1;
	}
	return v;
}

ll CalculateInvalidSum(const ll l, const ll r) {
	ll ans = 0;
	for (int i = 1;; ++i) {
		const ll n = stoll(to_string(i) + to_string(i));
		if (n < l) {
			continue;
		}

		if (r < n) {
			break;
		}

		ans += n;
	}
	return ans;
}

int main() {
	ll ans = 0;

	for (const auto [l, r] : ReadIdRanges()) {
		ans += CalculateInvalidSum(l, r);
	}

	cout << ans << '\n';

	return 0;
}