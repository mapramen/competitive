#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int NormalizeExpression(string& s) {
  map<char, int> M;
  for (char c : s) {
    if (islower(c)) {
      M[c] = 0;
    }
  }

  char d = 'a';
  for (auto& p : M) {
    p.second = d++;
  }

  for (char& c : s) {
    if (islower(c)) {
      c = M[c];
    }
  }

  return M.size();
}

bool Evaluate(string& s, int mask) {
  stack<bool> S;

  for (char c : s) {
    if (islower(c)) {
      S.push(mask & (1 << (c - 'a')));
      continue;
    }

    if (c == 'N') {
      bool a = S.top();
      S.pop();
      S.push(!a);
      continue;
    }

    bool a = S.top();
    S.pop();

    bool b = S.top();
    S.pop();

    if (c == 'C') {
      S.push(a && b);
      continue;
    }

    if (c == 'D') {
      S.push(a || b);
      continue;
    }

    if (c == 'I') {
      S.push(!a || b);
      continue;
    }

    S.push(a == b);
  }

  return S.top();
}

bool Solve() {
  string s;
  cin >> s;

  int n = NormalizeExpression(s);
  reverse(s.begin(), s.end());

  bool ans = true;
  for (int mask = 0; mask < (1 << n) && ans; ++mask) {
    ans = Evaluate(s, mask);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}