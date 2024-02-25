#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Sanitize(string s) {
  string t;
  for (char c : s) {
    if (isdigit(c) || c == '-' || c == '+' || c == '*' || c == 'x' || c == '=') {
      t.push_back(c);
    }
  }
  return t;
}

void Trim(string& s) {
  reverse(s.begin(), s.end());
  while (!s.empty() && !isdigit(s.back()) && s.back() != '-' && s.back() != '+' && s.back() != '=') {
    s.pop_back();
  }
  reverse(s.begin(), s.end());
}

ll ExtractNumber(string& s) {
  reverse(s.begin(), s.end());

  ll number = 0, sign = 1;
  if (!s.empty() && s.back() == '-') {
    sign = -1;
    s.pop_back();
  }

  if (!s.empty() && s.back() == '+') {
    s.pop_back();
  }

  while (!s.empty() && isdigit(s.back())) {
    number = number * 10 + s.back() - '0';
    s.pop_back();
  }

  reverse(s.begin(), s.end());

  return sign * number;
}

bool IsCharPresent(string& s, char c) {
  for (char x : s) {
    if (x == c) {
      return true;
    }
  }
  return false;
}

string Solve() {
  string s;
  cin >> s;

  s = Sanitize(s);

  ll a = max(1ll, ExtractNumber(s));

  Trim(s);
  ll b = ExtractNumber(s), c = 0;

  if (IsCharPresent(s, 'x')) {
    Trim(s);
    c = ExtractNumber(s);
  } else {
    c = b, b = 0;
  }

  ll D = b * b - 4 * a * c;

  if (D < 0) {
    return "Imaginary";
  }

  if (D == 0) {
    return "Equal";
  }

  return "Distinct real";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s roots.\n", Solve().c_str());
  }
  return 0;
}