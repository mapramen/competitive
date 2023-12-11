#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> GetFaraySequence(int n) {
  int a = 0, b = 1, c = 1, d = n;

  vector<pii> ans{{a, b}, {c, d}};
  while (c <= n) {
    int k = (n + b) / d;
    tie(a, b, c, d) = make_tuple(c, d, k * c - a, k * d - b);
    ans.push_back({c, d});
  }

  return ans;
}

void Solve() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<pii> faray_sequence = GetFaraySequence(n);

  while (q--) {
    int m;
    scanf("%d", &m);
    auto [p, q] = faray_sequence[m - 1];
    printf("%d/%d\n", p, q);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}