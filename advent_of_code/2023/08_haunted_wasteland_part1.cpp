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

int main() {
  string directions;
  cin >> directions;

  map<string, pair<string, string>> children = ReadMap();

  string node = "AAA";
  int ans = 0;

  while (node != "ZZZ") {
    char direction = directions[ans % directions.size()];
    if (direction == 'L') {
      node = children[node].first;
    } else {
      node = children[node].second;
    }
    ++ans;
  }

  cout << ans << endl;

  return 0;
}