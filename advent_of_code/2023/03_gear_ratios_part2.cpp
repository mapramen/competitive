#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void AddPart(vector<string>& s, vector<vector<set<int>>>& part_ids, int part_id, int x, int y) {
  for (int dx = -1; dx < 2; ++dx) {
    for (int dy = -1; dy < 2; ++dy) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= s.size() || ny < 0 || ny >= s[nx].size()) {
        continue;
      }

      if (s[nx][ny] != '.' && !isdigit(s[nx][ny])) {
        part_ids[nx][ny].insert(part_id);
      }
    }
  }
}

void AddPart(vector<string>& s, vector<vector<set<int>>>& part_ids, int part_id, int x, vector<int>& v) {
  for (int y : v) {
    AddPart(s, part_ids, part_id, x, y);
  }
}

int main() {
  vector<string> s;

  for (string line; getline(cin, line);) {
    s.push_back(line);
  }

  vector<vector<set<int>>> part_ids(s.size());
  for (int x = 0; x < s.size(); ++x) {
    part_ids[x].resize(s[x].size());
  }

  vector<int> parts;
  for (int n = s.size(), x = 0; x < n; ++x) {
    for (int m = s[x].size(), y = 0; y < m; ++y) {
      if (!isdigit(s[x][y])) {
        continue;
      }

      vector<int> v;
      for (; y < m && isdigit(s[x][y]); ++y) {
        v.push_back(y);
      }

      int part = stoi(s[x].substr(v.front(), v.size()));
      parts.push_back(part);

      AddPart(s, part_ids, parts.size() - 1, x, v);

      y = v.back();
    }
  }

  ll ans = 0;
  for (int x = 0; x < s.size(); ++x) {
    for (int y = 0; y < s[x].size(); ++y) {
      if (s[x][y] != '*' || part_ids[x][y].size() != 2) {
        continue;
      }

      ll ansx = 1;
      for (int part_id : part_ids[x][y]) {
        ansx *= parts[part_id];
      }

      ans += ansx;
    }
  }

  cout << ans << endl;

  return 0;
}