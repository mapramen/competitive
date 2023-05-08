#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

int least_prime_factor[N];

void Initialize() {
  for (int i = 2; i < N; ++i) {
    if (least_prime_factor[i] == 0) {
      for (int j = i; j < N; j += i) {
        if (least_prime_factor[j] == 0) {
          least_prime_factor[j] = i;
        }
      }
    }
  }
}

bool Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  return n == 1 || m == 1 || least_prime_factor[n] > m;
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}