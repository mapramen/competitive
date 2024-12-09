#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	string s;
	cin >> s;

	vector<int> a;
	for (int i = 0, k = 0; i < s.size(); ++i) {
		const int n = a.size() + s[i] - '0';
		a.resize(n, i % 2 == 0 ? k++ : -1);
	}

	for (int i = 0, j = a.size() - 1; i < j; --j) {
		if (a[j] == -1) {
			continue;
		}

		while (i < j && a[i] != -1) {
			++i;
		}

		swap(a[i], a[j]);
	}

	ll ans = 0;
	for (int i = 0; i < a.size() && a[i] != -1; ++i) {
		ans += 1ll * i * a[i];
	}
	cout << ans << endl;

	return 0;
}