#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 16777216
#define NUMBER_OF_ITERATIONS 2000
#define SEQUENCE_LENGTH 4

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

void AddSequenceToPrice(map<vector<int>, int>& sequence_to_price, int n, ll x) {
	set<vector<int>> visited;

	vector<int> sequence;
	for (int i = 1; i <= n; ++i) {
		const int previous_price = x % 10;

		x = CalculateNext(x);
		const int current_price = x % 10;

		const int diff = current_price - previous_price;
		sequence.push_back(diff);

		if (sequence.size() > SEQUENCE_LENGTH) {
			sequence.erase(sequence.begin());
		}

		if (sequence.size() != SEQUENCE_LENGTH) {
			continue;
		}

		if (visited.count(sequence)) {
			continue;
		}

		visited.insert(sequence);
		sequence_to_price[sequence] += current_price;
	}
}

int main() {
	vector<ll> a = ReadInputs();

	map<vector<int>, int> sequence_to_price;
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