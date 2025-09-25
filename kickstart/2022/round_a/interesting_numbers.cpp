#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 10

vector<int> Int2Vec(ll n) {
	vector<int> v;
	for (; n > 0; n /= 10) {
		v.push_back(n % 10);
	}
	reverse(v.begin(), v.end());
	return v;
}

int CalculateMaxPossibleProduct(const int sum, const int p) {
	return sum < p ? 1 : p * CalculateMaxPossibleProduct(sum / p, p);
}

int CalculateMaxPossibleProduct(const int sum) {
	return CalculateMaxPossibleProduct(sum, 2) * CalculateMaxPossibleProduct(sum, 3) * CalculateMaxPossibleProduct(sum, 5) * CalculateMaxPossibleProduct(sum, 7);
}

int CalculateNewProduct(const int P, const int p, const int d) {
	const int new_product = p * d;
	return new_product == 0 ? 0 : __gcd(P, new_product);
}

int CalculateNewSum(const int s, const int d) {
	return s + d;
}

int CalculateNewState(const int P, const int S, const int p, const int s, const int d) {
	return CalculateNewProduct(P, p, d) * S + CalculateNewSum(s, d);
}

bool IsValid(const ll p, const int s) {
	return p % s == 0;
}

ll Calculate(const ll n) {
	if (n == 0) {
		return 0ll;
	}

	const auto& v = Int2Vec(n);
	const int S = v[0] + (v.size() - 1) * 9 + 1;
	const int P = CalculateMaxPossibleProduct(S - 1);

	unordered_map<int, ll> dp_cur, dp_next;

	for (int d = 1; d < v[0]; ++d) {
		++dp_cur[CalculateNewState(P, S, 1, 0, d)];
	}

	int running_product = CalculateNewProduct(P, 1, v[0]), running_sum = CalculateNewSum(0, v[0]);

	for (int i = 1; i < v.size(); ++i) {
		dp_next.clear();

		for (const auto [k, cnt] : dp_cur) {
			const int p = k / S, s = k % S;
			for (int d = 0; d < B; ++d) {
				dp_next[CalculateNewState(P, S, p, s, d)] += cnt;
			}
		}

		for (int d = 1; d < B; ++d) {
			++dp_next[CalculateNewState(P, S, 1, 0, d)];
		}

		for (int d = 0; d < v[i]; ++d) {
			++dp_next[CalculateNewState(P, S, running_product, running_sum, d)];
		}

		running_product = CalculateNewProduct(P, running_product, v[i]);
		running_sum = CalculateNewSum(running_sum, v[i]);

		dp_cur.swap(dp_next);
	}

	ll ans = IsValid(running_product, running_sum);
	for (const auto [k, cnt] : dp_cur) {
		const int p = k / S, s = k % S;
		if (IsValid(p, s)) {
			ans += cnt;
		}
	}
	return ans;
}

ll Solve() {
	ll l, r;
	scanf("%lld%lld", &l, &r);
	return Calculate(r) - Calculate(l - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}