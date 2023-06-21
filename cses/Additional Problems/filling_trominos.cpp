// https://www.cut-the-knot.org/Curriculum/Games/LminoRect.shtml
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>

const vector<vector<pii>> tromino_set = {{{-1, 0}, {0, 0}, {0, 1}}, {{0, 0}, {0, 1}, {1, 0}}, {{-1, 0}, {0, -1}, {0, 0}}, {{0, -1}, {0, 0}, {1, 0}}};
const vector<pii> adjacent_set = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Set(vector<tiii>& trominos, bool transpose, int x, int y, int direction) {
  if (transpose) {
    swap(x, y);
    if (direction == 0 || direction == 3) {
      direction ^= 3;
    }
  }
  trominos.push_back({x, y, direction});
}

void Solve(vector<tiii>& trominos, int n, int m, bool transpose) {
  if (n == 0 || m == 0) {
    return;
  }

  if (m % 3 != 0 || n == 3) {
    Solve(trominos, m, n, !transpose);
    return;
  }

  if (n > 5 || n % 2 == 0) {
    Solve(trominos, n - 2, m, transpose);

    for (int y = 0; y < m; y += 3) {
      Set(trominos, transpose, n - 1, y, 0);
      Set(trominos, transpose, n - 2, y + 2, 3);
    }

    return;
  }

  assert(n == 5);

  if (m > 9 || m % 2 == 0) {
    Solve(trominos, n, m - 6, transpose);

    Set(trominos, transpose, 0, m - 4, 3);
    Set(trominos, transpose, 0, m - 1, 3);

    Set(trominos, transpose, 1, m - 6, 0);
    Set(trominos, transpose, 1, m - 3, 0);

    Set(trominos, transpose, 2, m - 5, 3);
    Set(trominos, transpose, 2, m - 3, 3);
    Set(trominos, transpose, 2, m - 1, 3);

    Set(trominos, transpose, 4, m - 6, 0);
    Set(trominos, transpose, 4, m - 4, 0);
    Set(trominos, transpose, 4, m - 2, 0);

    return;
  }

  assert(m == 9);

  Set(trominos, transpose, 0, 1, 3);
  Set(trominos, transpose, 0, 4, 3);
  Set(trominos, transpose, 0, 5, 1);
  Set(trominos, transpose, 0, 7, 1);

  Set(trominos, transpose, 1, 2, 0);

  Set(trominos, transpose, 2, 0, 0);
  Set(trominos, transpose, 2, 4, 3);
  Set(trominos, transpose, 2, 6, 2);
  Set(trominos, transpose, 2, 8, 2);

  Set(trominos, transpose, 3, 2, 2);
  Set(trominos, transpose, 3, 8, 3);

  Set(trominos, transpose, 4, 0, 0);
  Set(trominos, transpose, 4, 3, 2);
  Set(trominos, transpose, 4, 5, 2);
  Set(trominos, transpose, 4, 6, 0);
}

int GetAdjacentMask(vector<string>& s, int n, int m, int x, int y) {
  int mask = 0;
  for (pii p : adjacent_set) {
    int nx = x + p.first;
    int ny = y + p.second;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || !isalpha(s[nx][ny])) {
      continue;
    }
    mask |= (1 << (s[nx][ny] - 'A'));
  }
  return mask;
}

char GetCharacter(int mask) {
  for (int i = 0; i < 26; i++) {
    if ((mask & (1 << i)) == 0) {
      return 'A' + i;
    }
  }

  assert(false);
}

void FillCharacter(vector<string>& s, int n, int m, int x, int y, int direction) {
  int mask = 0;
  for (pii p : tromino_set[direction]) {
    int nx = x + p.first;
    int ny = y + p.second;
    mask |= GetAdjacentMask(s, n, m, nx, ny);
  }

  char c = GetCharacter(mask);
  for (pii p : tromino_set[direction]) {
    int nx = x + p.first;
    int ny = y + p.second;
    s[nx][ny] = c;
  }
}

vector<string> Solve(int n, int m) {
  vector<tiii> v;
  Solve(v, n, m, false);

  vector<string> s(n, string(m, '.'));
  for (auto [x, y, direction] : v) {
    FillCharacter(s, n, m, x, y, direction);
  }
  return s;
}

vector<string> Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (min(n, m) == 1 || (min(n, m) != 3 && (n * m) % 3 != 0) || (min(n, m) == 3 && max(n, m) % 2 != 0)) {
    return {};
  }

  return Solve(n, m);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<string> ans = Solve();

    if (ans.empty()) {
      printf("NO\n");
      continue;
    }

    printf("YES\n");
    for (string s : ans) {
      printf("%s\n", s.c_str());
    }
  }
  return 0;
}