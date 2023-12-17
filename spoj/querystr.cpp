#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ZFunction(string& s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }

    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

vector<int> Solve() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  vector<int> z = ZFunction(s);
  z[0] = s.size();

  int q;
  scanf("%d", &q);

  vector<int> ans;
  while (q--) {
    int i;
    scanf("%d", &i);
    ans.push_back(z[s.size() - i]);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int x : Solve()) {
      printf("%d\n", x);
    }
  }
  return 0;
}