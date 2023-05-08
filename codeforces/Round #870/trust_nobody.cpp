#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPossible(vector<int>& a, int l) {
  int cnt = 0;
  for (int x : a) {
    cnt += (l < x);
  }
  return cnt == l;
}

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  for (int l = n; l >= 0; --l) {
    if (IsPossible(a, l)) {
      return l;
    }
  }

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}