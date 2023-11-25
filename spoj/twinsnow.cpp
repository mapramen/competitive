#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 6

vector<int> GetReflectionInvariant(vector<int> v) {
  vector<int> u(v);
  reverse(u.begin(), u.end());
  return min(u, v);
}

vector<int> GetInvariant(vector<int> v) {
  int n = v.size();
  vector<int> ans = GetReflectionInvariant(v);

  v.insert(v.end(), v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    vector<int> u(v.begin() + i, v.begin() + i + n);
    ans = min(ans, GetReflectionInvariant(u));
  }

  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  set<vector<int>> S;
  while (n--) {
    vector<int> v(B);

    for (int& x : v) {
      scanf("%d", &x);
    }

    v = GetInvariant(v);
    if (S.count(v)) {
      printf("Twin snowflakes found.\n");
      return 0;
    }

    S.insert(v);
  }

  printf("No two snowflakes are alike.\n");

  return 0;
}