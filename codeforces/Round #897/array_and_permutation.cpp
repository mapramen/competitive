#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[a[i].second] = n - i;
  }

  return b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int x : Solve()) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}