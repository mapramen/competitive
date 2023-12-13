#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

bool is_prime[N];

void Initialize() {
  for (int i = 2; i < N; ++i) {
    is_prime[i] = true;
  }

  for (int i = 2; i * i < N; ++i) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i * i; j < N; j += i) {
      if (is_prime[j]) {
        is_prime[j] = false;
      }
    }
  }
}

ll Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  if (k == 0) {
    return 1ll * n * (n - 1) / 2;
  }

  ll ans = 0;
  for (int i = 2, j = 2; i <= n; ++i) {
    for (; j <= n && k > 0; ++j) {
      k -= is_prime[j];
    }

    if (k == 0) {
      ans += (n - j + 2);
    }

    k += is_prime[i];
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