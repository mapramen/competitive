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

bool IsValid(const ll n, const vector<ll>& a, const string& n_str, ll x, int i) {
	if (x > n) {
		return false;
	}

	if (i == a.size()) {
		return x == n;
	}

	if (IsValid(n, a, n_str, x + a[i], i + 1)) {
		return true;
	}

	if (IsValid(n, a, n_str, x * a[i], i + 1)) {
		return true;
	}

	string t = to_string(x) + to_string(a[i]);
	if (t.size() < n_str.size() || t.size() == n_str.size() && t <= n_str) {
		return IsValid(n, a, n_str, stoll(t), i + 1);
	}

	return false;
}

int main() {
	ll ans = 0;
	for (string line; getline(cin, line);) {
		auto [n, a] = ParseLine(line);
		const string n_str = to_string(n);
		if (IsValid(n, a, n_str, a[0], 1)) {
			ans += n;
		}
	}
	printf("%lld\n", ans);
	return 0;
}