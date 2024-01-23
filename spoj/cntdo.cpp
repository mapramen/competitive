#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  set<int> S;
  while (n--) {
    int x;
    scanf("%d", &x);
    S.insert(x);
  }

  int ans = 0;
  for (int x : S) {
    ans += (S.count(2 * x) != 0);
  }
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