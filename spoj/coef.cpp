#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 14

int fact[N];

void Initialize() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
  }
}

int Solve() {
  int n, k;
  if (scanf("%d %d", &n, &k) == EOF) {
    exit(0);
  }

  int ans = fact[n];
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    ans /= fact[x];
  }

  return ans;
}

int main() {
  Initialize();
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}