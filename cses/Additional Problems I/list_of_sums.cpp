#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve(map<int, int> cnt, int x) {
  vector<int> a{x};
  while (!cnt.empty()) {
    x = cnt.begin()->first - a.front();

    for (int y : a) {
      auto it = cnt.find(x + y);
      if (it == cnt.end() || it->second == 0) {
        return {};
      }
      --it->second;
    }

    while (!cnt.empty() && cnt.begin()->second == 0) {
      cnt.erase(cnt.begin());
    }

    a.push_back(x);
  }
  return a;
}

int main() {
  int n;
  scanf("%d", &n);

  map<int, int> cnt;
  vector<int> a;
  for (int k = n * (n - 1) / 2; k > 0; --k) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  a.resize(n);

  vector<int> ans;
  for (int z : a) {
    ans = Solve(cnt, (0ll + a[0] + a[1] + z) / 2 - z);
    if (!ans.empty()) {
      break;
    }
  }

  for (int x : ans) {
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}