#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int key;
  string s;
  cin >> key >> s;

  bool invert_case = key >= 26;
  key %= 26;

  for (char& c : s) {
    if (c == '.') {
      c = ' ';
      continue;
    }

    bool is_upper_case = isupper(c);
    if (invert_case) {
      is_upper_case = !is_upper_case;
    }

    c = tolower(c);
    c = (c - 'a' + key) % 26 + 'a';
    if (is_upper_case) {
      c = toupper(c);
    }
  }

  return s;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}