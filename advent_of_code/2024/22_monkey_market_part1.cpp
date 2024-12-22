#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 16777216
#define NUMBER_OF_ITERATIONS 2000

vector<ll> ReadInputs() {
	vector<ll> inputs;
	for (ll x; cin >> x; inputs.push_back(x));
	return inputs;
}

ll CalculateNext(ll x) {
	x = ((x * 64) ^ x) % MOD;
	x = ((x / 32) ^ x) % MOD;
	x = ((x * 2048) ^ x) % MOD;
	return x;
}

ll CalculateNext(int n, ll x) {
	for (int i = 0; i < n; i++) {
		x = CalculateNext(x);
	}
	return x;
}

int main() {
	vector<ll> a = ReadInputs();

	ll ans = 0;
	for (ll x : a) {
		ans += CalculateNext(NUMBER_OF_ITERATIONS, x);
	}
	cout << ans << endl;

	return 0;
}