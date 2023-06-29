#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Read(int n) {
  ll ans = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    ans += x;
  }
  return ans;
}

string Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  ll a = Read(n);
  ll b = Read(m);

  if (a == b) {
    return "Draw";
  }

  return a > b ? "Tsondu" : "Tenzing";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}