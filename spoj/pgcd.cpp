#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10000001

int mu[N], primes[N], g[N], sum_g[N];
bool is_prime[N];

void Initialize() {
  mu[1] = 1;
  for (int i = 2; i < N; ++i) {
    is_prime[i] = true;
  }

  int m = 0;
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      primes[m++] = i;
      mu[i] = -1;
      g[i] = 1;
    }

    for (int j = 0, t; j < m && (t = i * primes[j]) < N; ++j) {
      is_prime[t] = false;
      if (i % primes[j] == 0) {
        mu[t] = 0;
        g[t] = mu[i];
        break;
      }

      mu[t] = -mu[i];
      g[t] = mu[i] - g[i];
    }
  }

  for (int i = 1; i < N; ++i) {
    sum_g[i] = sum_g[i - 1] + g[i];
  }
}

ll Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n > m) {
    swap(n, m);
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int j = min(n / (n / i), m / (m / i));
    ans += 1ll * (sum_g[j] - sum_g[i - 1]) * (n / i) * (m / i);
    i = j;
  }

  return ans;
}

int main() {
  Initialize();

  int t;
  scanf("%d", &t);

  while (t--) {
    printf("%lld\n", Solve());
  }

  return 0;
}