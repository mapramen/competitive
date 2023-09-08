#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  string s;
  cin >> s;

  if (k % 2 == 0 && k != n) {
    sort(s.begin(), s.end());
    return s;
  }

  vector<vector<char>> V(2);
  for (int i = 0; i < n; ++i) {
    V[i % 2].push_back(s[i]);
  }

  for (int x = 0; x < 2; ++x) {
    sort(V[x].begin(), V[x].end());
  }

  if (k == n) {
    sort(V.begin(), V.end());
  }

  for (int x = 0; x < 2; ++x) {
    reverse(V[x].begin(), V[x].end());
  }

  for (int i = 0; i < n; ++i) {
    int x = i % 2;
    s[i] = V[x].back();
    V[x].pop_back();
  }

  return s;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}