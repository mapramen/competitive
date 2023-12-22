#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  ll n;
  scanf("%lld", &n);
  return n % 3 != 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "Hemlata" : "Ritu");
  }
  return 0;
}