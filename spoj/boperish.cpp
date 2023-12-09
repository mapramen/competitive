#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  sort(a.begin(), a.end(), greater<int>());

  int ans = 1;
  for (; ans <= a.size() && a[ans - 1] >= ans; ++ans)
    ;
  --ans;

  return ans;
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}