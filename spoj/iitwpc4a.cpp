#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetFinalLength(string& s, int m, int n) {
  ll final_length = s.size();

  int cnt = 0;
  for (char c : s) {
    if (c != 'a') {
      cnt = 0;
      continue;
    }

    ++cnt;
    if (cnt == m) {
      final_length += (n - m);
      cnt = 0;
    }
  }

  return final_length;
}

pll Solve() {
  int n, m;
  string s;

  cin >> s >> m >> n;

  ll initial_length = s.length();
  ll final_length = GetFinalLength(s, m, n);

  ll max_length = max(initial_length, final_length);
  ll min_length = min(initial_length, final_length);

  return {min_length, max_length};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [min_length, max_length] = Solve();
    printf("%lld %lld\n", min_length, max_length);
  }
  return 0;
}