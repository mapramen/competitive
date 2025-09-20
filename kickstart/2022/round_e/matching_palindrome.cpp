#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
	int n;
	string s;
	cin >> n >> s;

	const string t = s + "#" + s;

	vector<int> pi(t.size() + 1);
	for (int i = 2, k = 0; i <= t.size(); ++i) {
		const char c = t[i - 1];
		while (t[k] != c && k != 0) {
			k = pi[k];
		}
		k += (t[k] == c);
		pi[i] = k;
	}

	int k = n;
	for (int i = pi[n]; i != 0; i = pi[i]) {
		const int ki = n - i;
		if (n % ki == 0 && pi[n + 1 + ki] == ki) {
			k = ki;
			break;
		}
	}

	return s.substr(0, k);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}