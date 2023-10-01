#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

char S[100];

int GetValue(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return c - 'A' + 10;
}

char GetChar(int n) {
  if (n < 10) {
    return n + '0';
  }
  return n - 10 + 'A';
}

ll ToDecimal(string s, int from_base) {
  ll res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = res * from_base + GetValue(s[i]);
  }
  return res;
}

string FromDecimal(ll n, int to_base) {
  string res;
  while (n) {
    int rem = n % to_base;
    res.push_back(GetChar(rem));
    n /= to_base;
  }
  reverse(res.begin(), res.end());
  return res;
}

string Solve() {
  int from_base, to_base;
  if (scanf("%s%d%d", S, &from_base, &to_base) == EOF) {
    exit(0);
  }

  string ans = FromDecimal(ToDecimal(string(S), from_base), to_base);

  return ans.size() > 7 ? "ERROR" : ans;
}

int main() {
  while (true) {
    printf("%7s\n", Solve().c_str());
  }
  return 0;
}