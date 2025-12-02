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
	const string r_str = to_string(r);

	unordered_set<ll> invalids;
	for (int i = 1;; ++i) {
		const string i_str = to_string(i);
		string n_str = i_str + i_str;

		if (r < stoll(n_str)) {
			break;
		}

		for (; n_str.size() < r_str.size() || (n_str.size() == r_str.size() && n_str <= r_str); n_str += i_str) {
			const ll n = stoll(n_str);
			if (n < l) {
				continue;
			}
			invalids.insert(n);
		}
	}

	return accumulate(invalids.begin(), invalids.end(), 0ll);
}

int main() {
	ll ans = 0;

	for (const auto [l, r] : ReadIdRanges()) {
		ans += CalculateInvalidSum(l, r);
	}

	cout << ans << '\n';

	return 0;
}