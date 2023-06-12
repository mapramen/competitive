#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  if (k * k < n) {
    return vector<int>();
  }

  vector<int> ans;
  for (int x = 0, val = 0; x < k; ++x) {
    int l = ans.size();
    for (int m = n / k + (x < n % k); m > 0; --m) {
      ans.push_back(++val);
    }
    reverse(ans.begin() + l, ans.end());
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> ans = Solve();

    if (ans.empty()) {
      printf("IMPOSSIBLE\n");
      continue;
    }

    for (int x : ans) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}