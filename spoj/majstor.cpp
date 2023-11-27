#include <bits/stdc++.h>

using namespace std;

#define N 51
#define B 3

char s[N];

int Char2Int(char c) {
  if (c == 'R') {
    return 0;
  }

  if (c == 'P') {
    return 1;
  }

  return 2;
}

vector<int> Read(int n) {
  scanf("%s", s);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = Char2Int(s[i]);
  }
  return a;
}

int GetScore(int y, int x) {
  if (x == y) {
    return 1;
  }

  if ((y + 1) % B == x) {
    return 2;
  }

  return 0;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<int> a = Read(n);
  vector<vector<int>> dp(n, vector<int>(B));

  int m;
  scanf("%d", &m);

  while (m--) {
    vector<int> b = Read(n);
    for (int i = 0; i < n; ++i) {
      for (int x = 0; x < B; ++x) {
        dp[i][x] += GetScore(b[i], x);
      }
    }
  }

  int score = 0, opt_score = 0;
  for (int i = 0; i < n; ++i) {
    score += dp[i][a[i]];
    opt_score += *max_element(dp[i].begin(), dp[i].end());
  }

  printf("%d\n%d\n", score, opt_score);

  return 0;
}