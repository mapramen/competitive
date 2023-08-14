#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define K 100

void AddToAns(vector<pii>& ans, vector<int>& a, int i, int j) {
  a[i] += a[j];
  ans.push_back({i + 1, j + 1});
}

vector<pii> SolvePositive(vector<int> a) {
  int k = max_element(a.begin(), a.end()) - a.begin();
  if (a[k] <= 0) {
    return vector<pii>(K);
  }

  vector<pii> ans;

  int mn = *min_element(a.begin(), a.end());
  while (a[k] + mn < 0) {
    AddToAns(ans, a, k, k);
  }

  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      AddToAns(ans, a, i, k);
    }
  }

  for (int i = 1; i < n; ++i) {
    AddToAns(ans, a, i, i - 1);
  }

  return ans;
}

vector<pii> SolveNegative(vector<int> a) {
  int k = min_element(a.begin(), a.end()) - a.begin();
  if (a[k] >= 0) {
    return vector<pii>(K);
  }

  vector<pii> ans;

  int mx = *max_element(a.begin(), a.end());
  while (a[k] + mx > 0) {
    AddToAns(ans, a, k, k);
  }

  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      AddToAns(ans, a, i, k);
    }
  }

  for (int i = n - 2; i >= 0; --i) {
    AddToAns(ans, a, i, i + 1);
  }

  return ans;
}

vector<pii> Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<pii> ans = SolvePositive(a);
  vector<pii> tmp = SolveNegative(a);
  if (tmp.size() < ans.size()) {
    ans = tmp;
  }

  if (ans.size() == K) {
    ans.clear();
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<pii> ans = Solve();
    printf("%lu\n", ans.size());
    for (auto [i, j] : ans) {
      printf("%d %d\n", i, j);
    }
  }
  return 0;
}