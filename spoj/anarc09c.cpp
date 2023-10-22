#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

int least_prime_factor[N];

void Initialize() {
  for (int i = 0; i < N; i++) {
    least_prime_factor[i] = i;
  }

  least_prime_factor[1] = INT_MAX;
  for (int i = 2; i * i < N; i++) {
    if (least_prime_factor[i] != i) {
      continue;
    }

    for (int j = i * i; j < N; j += i) {
      if (least_prime_factor[j] == j) {
        least_prime_factor[j] = i;
      }
    }
  }
}

pii Solve() {
  int a, b;
  scanf("%d%d", &a, &b);

  if (a == 0 && b == 0) {
    exit(0);
  }

  int dimension = 0, distance = 0;
  while (a != 1 || b != 1) {
    int p = min(least_prime_factor[a], least_prime_factor[b]);

    int x = 0;
    while (a % p == 0) {
      a /= p, ++x;
    }

    while (b % p == 0) {
      b /= p, --x;
    }

    ++dimension;
    distance += abs(x);
  }

  return {dimension, distance};
}

int main() {
  Initialize();
  for (int k = 1;; ++k) {
    auto [dimension, distance] = Solve();
    printf("%d. %d:%d\n", k, dimension, distance);
  }
  return 0;
}