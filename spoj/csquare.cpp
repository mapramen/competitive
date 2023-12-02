#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int a, m;
  string b;
  cin >> a >> b >> m;

  int ans = 1;

  while (!b.empty()) {
    char c = b.back();
    b.pop_back();

    int x = a;

    if (c == '1') {
      ans = (1ll * ans * x) % m;
    }

    x = (1ll * x * a) % m;
    if (c == '2') {
      ans = (1ll * ans * x) % m;
    }

    x = (1ll * x * a) % m;
    a = x;
  }

  ans %= m;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}