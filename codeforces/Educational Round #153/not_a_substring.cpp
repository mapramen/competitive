#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPresent(string s, string p) {
  return s.find(p) != string::npos;
}

string Solve() {
  string s;
  cin >> s;

  int n = s.size();
  string a = string(n, '(') + string(n, ')');
  if (!IsPresent(a, s)) {
    return a;
  }

  a.clear();
  for (int i = 0; i < n; ++i) {
    a.push_back('(');
    a.push_back(')');
  }

  if (!IsPresent(a, s)) {
    return a;
  }

  return "";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string ans = Solve();
    if (ans.empty()) {
      printf("NO\n");
    } else {
      printf("YES\n");
      printf("%s\n", ans.c_str());
    }
  }
  return 0;
}