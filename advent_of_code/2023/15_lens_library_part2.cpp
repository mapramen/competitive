#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 256

vector<vector<pair<string, int>>> boxes(B);

int GetHashValue(string s) {
  int ans = 0;
  for (char c : s) {
    ans += c;
    ans *= 17;
    ans %= B;
  }
  return ans;
}

void Add(string s, int d) {
  int h = GetHashValue(s);

  for (auto& p : boxes[h]) {
    if (p.first == s) {
      p.second = d;
      return;
    }
  }

  boxes[h].push_back({s, d});
}

void Remove(string s) {
  int h = GetHashValue(s);

  for (auto it = boxes[h].begin(); it != boxes[h].end(); it++) {
    if (it->first == s) {
      boxes[h].erase(it);
      return;
    }
  }
}

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  string label;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isalpha(c)) {
      label.push_back(c);
      continue;
    }

    if (c == '-') {
      Remove(label);
      label.clear();
    } else {
      Add(label, s.back() - '0');
      label.clear();
      s.pop_back();
    }

    if (!s.empty()) {
      s.pop_back();
    }
  }

  ll ans = 0;
  for (int h = 0; h < B; ++h) {
    for (int i = 0; i < boxes[h].size(); ++i) {
      auto [_, f] = boxes[h][i];
      ans += 1ll * (h + 1) * (i + 1) * f;
    }
  }
  printf("%lld\n", ans);

  return 0;
}