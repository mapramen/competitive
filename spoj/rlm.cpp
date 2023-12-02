#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll ReadNumber(string& s) {
  ll ans = 0;
  while (!s.empty()) {
    if (isspace(s.back())) {
      s.pop_back();
      continue;
    }

    if (!isdigit(s.back())) {
      break;
    }

    int cnt = s.back() - '0';
    s.pop_back();
    int d = s.back() - '0';
    s.pop_back();

    while (cnt--) {
      ans = 10 * ans + d;
    }
  }
  return ans;
}

char ReadOperator(string& s) {
  while (!s.empty() && isspace(s.back())) {
    s.pop_back();
  }

  char op = s.back();
  s.pop_back();

  return op;
}

string GetRunLengthEncoding(ll x) {
  string ans;

  string s = to_string(x);
  reverse(s.begin(), s.end());

  while (!s.empty()) {
    int d = s.back() - '0';
    int cnt = 0;

    while (!s.empty() && s.back() - '0' == d && cnt < 9) {
      ++cnt;
      s.pop_back();
    }

    ans.push_back('0' + cnt);
    ans.push_back('0' + d);
  }

  return ans;
}

string Solve() {
  string s;
  if (!getline(cin, s)) {
    exit(0);
  }

  reverse(s.begin(), s.end());

  ll a = ReadNumber(s);
  char op = ReadOperator(s);
  ll b = ReadNumber(s);

  ll ans = 0;
  if (op == '+') {
    ans = a + b;
  } else if (op == '-') {
    ans = a - b;
  } else if (op == '*') {
    ans = a * b;
  } else {
    ans = a / b;
  }

  return GetRunLengthEncoding(a) + " " + op + " " + GetRunLengthEncoding(b) + " = " + GetRunLengthEncoding(ans);
}

int main() {
  while (true) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}