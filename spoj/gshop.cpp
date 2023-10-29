#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  priority_queue<int, vector<int>, greater<int>> Q;
  while (n--) {
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  while (k--) {
    int x = Q.top();
    Q.pop();
    Q.push(-x);
  }

  int ans = 0;
  while (!Q.empty()) {
    ans += Q.top();
    Q.pop();
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}