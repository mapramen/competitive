#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string GetInvariant(string s) {
  string ans;
  for (char c : s) {
    if (!ans.empty() && ans.back() == c) {
      continue;
    }
    ans.push_back(c);
  }
  return ans;
}

bool IsPalindrome(string s) {
  for (int n = s.size(), i = 0, j = n - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

bool Solve() {
  string s;
  cin >> s;
  return IsPalindrome(GetInvariant(s));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}