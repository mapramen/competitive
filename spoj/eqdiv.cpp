#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ExtractNumber(string& s) {
  int ans = 0;

  while (!s.empty() && !isdigit(s.back())) {
    s.pop_back();
  }

  while (!s.empty() && isdigit(s.back())) {
    ans = ans * 10 + (s.back() - '0');
    s.pop_back();
  }

  return ans - 1;
}

vector<int> ReadNumbers() {
  string s;

  while (s.empty()) {
    getline(cin, s);
  }

  reverse(s.begin(), s.end());

  vector<int> ans;
  while (!s.empty()) {
    ans.push_back(ExtractNumber(s));
  }

  return ans;
}

void DFS(int n, int k, vector<vector<int>>& a, int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] != k) {
    return;
  }

  a[x][y] = -1;

  DFS(n, k, a, x - 1, y);
  DFS(n, k, a, x + 1, y);
  DFS(n, k, a, x, y - 1);
  DFS(n, k, a, x, y + 1);
}

bool Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<vector<int>> a(n, vector<int>(n));

  for (int k = 1; k < n; ++k) {
    vector<int> b = ReadNumbers();
    for (int i = 0; i < 2 * n; i += 2) {
      a[b[i]][b[i + 1]] = k;
    }
  }

  vector<vector<pii>> V(n);
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      V[a[x][y]].push_back({x, y});
    }
  }

  for (auto& v : V) {
    if (v.size() != n) {
      return false;
    }
  }

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      if (a[x][y] == -1) {
        continue;
      }

      int k = a[x][y];
      if (V[k].empty()) {
        return false;
      }

      V[k].clear();
      DFS(n, k, a, x, y);
    }
  }

  return true;
}

int main() {
  while (true) {
    printf("%s\n", Solve() ? "good" : "wrong");
  }
  return 0;
}