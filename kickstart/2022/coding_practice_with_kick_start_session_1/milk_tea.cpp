#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Calculate(const vector<int>& a, const string& s) {
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		ans += s[i] == '0' ? 0 : a[i];
	}
	return ans;
}

int Solve() {
	int n, m, p;
	cin >> n >> m >> p;

	vector<int> a(p);
	for (int x = 0; x < n; ++x) {
		string s;
		cin >> s;

		for (int i = 0; i < p; ++i) {
			a[i] += s[i] != '0';
		}
	}

	vector<bool> min_bit(p);
	int base_ans = 0;
	for (int i = 0; i < p; ++i) {
		const int z_cnt = a[i];
		const int o_cnt = n - z_cnt;
		if (o_cnt < z_cnt) {
			a[i] = o_cnt;
			min_bit[i] = true;
		}

		base_ans += a[i];
		a[i] = abs(z_cnt - o_cnt);
	}

	vector<int> idxs(p);
	iota(idxs.begin(), idxs.end(), 0);
	sort(idxs.begin(), idxs.end(), [&](const int i, const int j) { return a[i] > a[j]; });
	sort(a.begin(), a.end(), greater<int>());

	unordered_set<string> forbidden;
	while (m--) {
		string s;
		cin >> s;

		for (int i = 0; i < p; ++i) {
			if (min_bit[i]) {
				s[i] = '0' + (1 ^ (s[i] - '0'));
			}
		}

		string t(p, '0');
		for (int i = 0; i < p; ++i) {
			t[i] = s[idxs[i]];
		}
		forbidden.insert(t);
	}

	int ans = n * p;
	for (int k = 0; k <= p; ++k) {
		string s = string(p - k, '0') + string(k, '1');
		while (forbidden.count(s) != 0 && next_permutation(s.begin(), s.end()));

		if (forbidden.count(s) != 0) {
			continue;
		}

		ans = min(ans, base_ans + Calculate(a, s));
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}