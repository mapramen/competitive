#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pair<ll, vector<ll>> ParseLine(string line) {
	stringstream ss(line);
	ll n;				 // The number before ":"
	char colon;	 // To consume the ':' character
	ss >> n >> colon;

	vector<ll> numbers;
	ll num;

	// Parse the rest of the line
	while (ss >> num) {
		numbers.push_back(num);
	}

	return {n, numbers};
}

bool IsValid(ll n, vector<ll> a) {
	unordered_set<ll> s, new_s;
	s.insert(a[0]);

	for (int i = 1; i < a.size(); ++i) {
		new_s.clear();
		for (ll x : s) {
			new_s.insert(min(n + 1, x + a[i]));
			new_s.insert(min(n + 1, x * a[i]));
		}
		s.swap(new_s);
	}

	return s.find(n) != s.end();
}

int main() {
	ll ans = 0;
	for (string line; getline(cin, line);) {
		auto [n, a] = ParseLine(line);
		if (IsValid(n, a)) {
			ans += n;
		}
	}
	printf("%lld\n", ans);
	return 0;
}