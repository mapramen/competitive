#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  map<string, int> C;

  for (int k = 0; k < 16; ++k) {
    string t1, t2;
    int g1, g2;
    cin >> t1 >> t2 >> g1 >> g2;
    string t = g1 > g2 ? t1 : t2;
    ++C[t];
  }

  string ans;
  int max_win = 0;
  for (auto [t, win] : C) {
    if (win > max_win) {
      max_win = win;
      ans = t;
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}