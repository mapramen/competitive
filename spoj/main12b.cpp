#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

bool is_prime[N];
vector<int> primes;

void Initialize() {
	for (int i = 2; i < N; ++i) {
		is_prime[i] = true;
	}

	for (int i = 2; i * i < N; ++i) {
		if (!is_prime[i]) {
			continue;
		}

		for (int j = i * i; j < N; j += i) {
			is_prime[j] = false;
		}
	}

	for (int i = 2; i < N; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}
}

vector<ll> Solve() {
	int n;
	scanf("%d", &n);

	set<ll> S;
	while (n--) {
		ll x;
		scanf("%lld", &x);

		for (int p : primes) {
			if (1ll * p * p > x) {
				break;
			}

			if (x % p != 0) {
				continue;
			}

			while (x % p == 0) {
				x /= p;
			}

			S.insert(p);
		}

		if (x > 1) {
			S.insert(x);
		}
	}

	return vector<ll>(S.begin(), S.end());
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t; ++k) {
		vector<ll> ans = Solve();

		printf("Case #%d: %lu\n", k, ans.size());
		for (ll x : ans) {
			printf("%lld\n", x);
		}
	}

	return 0;
}