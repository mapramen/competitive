#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

map<string, pair<string, string>> ReadMap() {
  map<string, pair<string, string>> children;
  string s;
  while (getline(cin, s)) {
    if (s.empty()) {
      continue;
    }

    string node = s.substr(0, 3);
    string left = s.substr(7, 3);
    string right = s.substr(12, 3);
    children[node] = {left, right};
  }
  return children;
}

int GetDistance(map<string, pair<string, string>>& children, string& directions, string node) {
  int ans = 0;

  while (node.back() != 'Z') {
    char direction = directions[ans % directions.size()];
    if (direction == 'L') {
      node = children[node].first;
    } else {
      node = children[node].second;
    }
    ++ans;
  }

  return ans;
}

int main() {
  string directions;
  cin >> directions;

  map<string, pair<string, string>> children = ReadMap();

  ll ans = 1;

  for (auto [k, _] : children) {
    if (k.back() != 'A') {
      continue;
    }
    ll ansx = GetDistance(children, directions, k);
    ans = lcm(ans, ansx);
  }

  cout << ans << endl;

  return 0;
}