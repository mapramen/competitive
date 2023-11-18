#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000000

vector<int> a;

void Initialize() {
  a.push_back(1);
  for (int i = 0; a.size() < N; ++i) {
    int cnt = a[i];
    int val = a.back() + 1;
    while (cnt--) {
      a.push_back(val);
    }
  }
}

int Solve() {
  int n;
  scanf("%d", &n);
  return a[n - 1];
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}