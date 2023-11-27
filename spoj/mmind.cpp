#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tguess tuple<vector<int>, int, int>
#define N 10

bool bulled[N], cowed[N];

tguess ReadGuess(int n) {
  vector<int> g(n);
  for (int& x : g) {
    scanf("%d", &x);
  }

  int bull, cow;
  scanf("%d%d", &bull, &cow);
  return {g, bull, cow};
}

pii GetRemainingBullCowCount(int n, vector<int>& a, tguess& guess) {
  auto [g, bull, cow] = guess;

  for (int i = 0; i < n; ++i) {
    if (a[i] == g[i]) {
      bull--;
      bulled[i] = true;
    } else {
      bulled[i] = false;
    }
    cowed[i] = false;
  }

  for (int i = 0; i < n && a[i] != 0; ++i) {
    if (bulled[i]) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      if (bulled[j] || cowed[j]) {
        continue;
      }
      if (a[i] == g[j]) {
        cow--;
        cowed[j] = true;
        break;
      }
    }
  }

  return {bull, cow};
}

vector<int> Solve(int n, int m, vector<tguess>& guesses, vector<int>& a, int i) {
  for (auto& guess : guesses) {
    auto [bull, cow] = GetRemainingBullCowCount(n, a, guess);
    if (bull < 0 || bull + cow > n - i || (i == n && (bull != 0 || cow != 0)) || (i < n && bull + cow < 0)) {
      return {};
    }
  }

  if (i == n) {
    return a;
  }

  for (int x = 1; x <= m; ++x) {
    a[i] = x;
    vector<int> ans = Solve(n, m, guesses, a, i + 1);
    if (!ans.empty()) {
      return ans;
    }
  }

  a[i] = 0;
  return {};
}

vector<int> Solve() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  vector<tguess> guesses;
  for (int i = 0; i < q; ++i) {
    guesses.push_back(ReadGuess(n));
  }

  vector<int> a(n);
  return Solve(n, m, guesses, a, 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> ans = Solve();
    if (ans.empty()) {
      printf("You are cheating!\n");
    } else {
      for (int x : ans) {
        printf("%d ", x);
      }
      printf("\n");
    }
  }
  return 0;
}