#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int ans = 0;
  priority_queue<int> Q;
  while (n--) {
    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s) {
      cnt += (c == '*');
    }

    ans += cnt;
    Q.push(m - 2 * cnt);
  }

  while (k--) {
    int x = Q.top();
    Q.pop();
    ans += x;
    Q.push(-x);
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