#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  ll ans = 0;
  priority_queue<int> Q;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);

    Q.push(x);
    Q.push(x);

    ans += Q.top() - x;
    Q.pop();
  }

  printf("%lld\n", ans);

  return 0;
}