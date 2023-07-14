#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

stack<int> S;

int Update(int x) {
  int ans = 0;
  while (!S.empty() && S.top() > x) {
    S.pop();
    ++ans;
  }

  if (x != 0 && (S.empty() || S.top() < x)) {
    S.push(x);
  }

  return ans;
}

int Solve() {
  int n;
  if (scanf("%d", &n) == EOF) {
    exit(0);
  }

  int ans = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    ans += Update(x);
  }

  ans += Update(0);
  return ans;
}

int main() {
  for (int k = 1;; ++k) {
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}