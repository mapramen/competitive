#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n;
	scanf("%d", &n);

	vector<tuple<string, int, int>> a;
	while (n--) {
		string c;
		int d, u;
		cin >> c >> d >> u;
		a.push_back({c, d, u});
	}

	vector<int> ada_indxs(a.size());
	iota(ada_indxs.begin(), ada_indxs.end(), 0);

	vector<int> charles_indxs(a.size());
	iota(charles_indxs.begin(), charles_indxs.end(), 0);

	sort(ada_indxs.begin(), ada_indxs.end(), [&](const int i, const int j) { return get<0>(a[i]) < get<0>(a[j]) || get<0>(a[i]) == get<0>(a[j]) && get<2>(a[i]) < get<2>(a[j]); });

	sort(charles_indxs.begin(), charles_indxs.end(), [&](const int i, const int j) { return get<1>(a[i]) < get<1>(a[j]) || get<1>(a[i]) == get<1>(a[j]) && get<2>(a[i]) < get<2>(a[j]); });

	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		ans += ada_indxs[i] == charles_indxs[i];
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