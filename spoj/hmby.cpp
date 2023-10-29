#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 5

int main() {
  ll ans = 0;
  for (int i = 1; i <= B; ++i) {
    ll x;
    cin >> x;
    ans += (1 << i) * x;
  }

  int w;
  cin >> w;

  printf("%s\n", w % 2 == 0 && w <= ans ? "YES" : "NO");

  return 0;
}