#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const ll INF = 1E16;

vector<ll> fibs;

void Initialize() {
  fibs.push_back(1);
  fibs.push_back(1);
  while (fibs.back() < INF) {
    fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
  }
}

ll Solve() {
  ll n;
  scanf("%lld", &n);

  ll ans = 0;
  while (n > 0) {
    int i = upper_bound(fibs.begin(), fibs.end(), n) - fibs.begin();
    ans += fibs[i];
    n -= fibs[i - 1];
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