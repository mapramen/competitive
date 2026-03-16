#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 26

void CharacterizeCnt(vector<int>& cnt) {
  for (int x : cnt) {
    if (x == 0) {
      return;
    }
  }

  for (int& x : cnt) {
    --x;
  }
}

int main() {
  string s;
  cin >> s;

  vector<int> char_map(B, -1);
  vector<int> cnt;
  for (char c : s) {
    if (char_map[c - 'a'] != -1) {
      continue;
    }

    int k = 0;
    for (int x : char_map) {
      k += (x != -1);
    }

    char_map[c - 'a'] = k;
    cnt.push_back(0);
  }

  map<vector<int>, int> dp;
  dp[cnt] = 1;

  ll ans = 0;
  for (char c : s) {
    ++cnt[char_map[c - 'a']];
    CharacterizeCnt(cnt);
    ans += dp[cnt];
    ++dp[cnt];
  }

  printf("%lld\n", ans);

  return 0;
}