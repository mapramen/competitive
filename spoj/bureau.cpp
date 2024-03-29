#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string ReadString() {
  char s[10];
  scanf("%s", s);
  return string(s);
}

vector<int> Solve() {
  int n;
  scanf("%d", &n);

  vector<vector<int>> adj(n + 1);

  for (int i = 1; i <= n; ++i) {
    string s = ReadString();
    if (s[0] == 'c') {
      int p;
      scanf("%d", &p);
      adj[p].push_back(i);
    }
  }

  vector<bool> active(n + 1, true);
  for (int i = n; i > 0; --i) {
    for (int j : adj[i]) {
      if (active[j]) {
        active[i] = false;
        break;
      }
    }
  }

  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (active[i]) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> ans = Solve();
    printf("%lu\n", ans.size());
    for (int x : ans) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}