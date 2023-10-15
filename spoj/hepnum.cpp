#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

char s[N];

string ReadNumber() {
  scanf("%s", s);

  if (s[0] == '*') {
    exit(0);
  }

  int n = strlen(s);

  int i = 0;
  while (i + 1 < n && s[i] == '0') {
    ++i;
  }

  return string(s + i, s + n);
}

char Solve() {
  string a = ReadNumber();
  string b = ReadNumber();

  if (a.size() < b.size()) {
    return '<';
  }

  if (a.size() > b.size()) {
    return '>';
  }

  return a < b ? '<' : (a > b ? '>' : '=');
}

int main() {
  while (true) {
    printf("%c\n", Solve());
  }
  return 0;
}