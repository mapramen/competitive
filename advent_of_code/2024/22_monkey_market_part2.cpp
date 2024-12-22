#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 16777216
#define NUMBER_OF_ITERATIONS 2000
#define SEQUENCE_LENGTH 4
#define PRICE_MOD 10

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

void AddSequenceToPrice(unordered_map<int, int>& sequence_to_price, int n, ll x) {
	unordered_set<int> visited;

	int remove_rolling_hash_power = 1;
	for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
		remove_rolling_hash_power *= 2 * PRICE_MOD;
	}

	queue<int> Q;
	int rolling_hash = 0;
	for (int i = 1; i <= n; ++i) {
		const int previous_price = x % PRICE_MOD;

		x = CalculateNext(x);
		const int current_price = x % PRICE_MOD;

		const int diff = PRICE_MOD + current_price - previous_price;
		rolling_hash = rolling_hash * (2 * PRICE_MOD) + diff;
		Q.push(diff);

		if (Q.size() > SEQUENCE_LENGTH) {
			rolling_hash -= Q.front() * remove_rolling_hash_power;
			Q.pop();
		}

		if (Q.size() != SEQUENCE_LENGTH) {
			continue;
		}

		if (visited.count(rolling_hash)) {
			continue;
		}

		visited.insert(rolling_hash);
		sequence_to_price[rolling_hash] += current_price;
	}
}

int main() {
	vector<ll> a = ReadInputs();

	unordered_map<int, int> sequence_to_price;
	for (ll x : a) {
		AddSequenceToPrice(sequence_to_price, NUMBER_OF_ITERATIONS, x);
	}

	int ans = 0;
	for (const auto& [sequence, price] : sequence_to_price) {
		ans = max(ans, price);
	}
	cout << ans << endl;

	return 0;
}