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
    S.insert(x - 1);
  }
  S.erase(0);

  int ans = 0;
  while (!S.empty()) {
    ++ans;
    for (int x = *S.begin(), y = x; !S.empty() && y <= *S.rbegin(); y += x) {
      S.erase(y);
    }
  }
  return ans;
}

int main() {
  int t = 1;
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}