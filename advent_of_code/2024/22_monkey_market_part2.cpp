#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 16777216
#define NUMBER_OF_ITERATIONS 2000
#define SEQUENCE_LENGTH 4
#define PRICE_MOD 10

const int MAXN = int(pow(2 * PRICE_MOD, SEQUENCE_LENGTH));

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

void AddSequenceToPrice(vector<int>& sequence_to_price, int n, ll x) {
	vector<bool> visited(MAXN);

	vector<int> a(n + 1);
	int rolling_hash = 0;
	for (int i = 1; i <= n; ++i) {
		const int previous_price = x % PRICE_MOD;

		x = CalculateNext(x);
		const int current_price = x % PRICE_MOD;

		const int diff = PRICE_MOD + current_price - previous_price;
		rolling_hash = rolling_hash * (2 * PRICE_MOD) + diff;
		a[i] = diff;

		if (i < SEQUENCE_LENGTH) {
			continue;
		}

		if (i > SEQUENCE_LENGTH) {
			rolling_hash -= a[i - SEQUENCE_LENGTH] * MAXN;
		}

		if (visited[rolling_hash]) {
			continue;
		}

		visited[rolling_hash] = true;
		sequence_to_price[rolling_hash] += current_price;
	}
}

int main() {
	vector<ll> a = ReadInputs();

	vector<int> sequence_to_price(MAXN);
	for (ll x : a) {
		AddSequenceToPrice(sequence_to_price, NUMBER_OF_ITERATIONS, x);
	}

	int ans = *max_element(sequence_to_price.begin(), sequence_to_price.end());
	cout << ans << endl;

	return 0;
}