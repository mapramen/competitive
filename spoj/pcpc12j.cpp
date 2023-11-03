#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> cnt(N);
  while (n--) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }

  pii ans = {0, 0};
  for (int i = 1; i < N; ++i) {
    if (cnt[i] % i != 0) {
      continue;
    }
    ans = max(ans, {cnt[i], -i});
  }

  return ans.first == 0 ? -1 : -ans.second;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}