#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ExtractNumber(string& s) {
  int ans = 0;
  while (s.back() != ' ') {
    ans = ans * 10 + (s.back() - '0');
    s.pop_back();
  }
  s.pop_back();
  return ans;
}

string EncodeString(string s) {
  string ans;
  for (char c : s) {
    int x = c == ' ' ? 0 : c - 'A' + 1;
    for (char d : bitset<5>(x).to_string()) {
      ans.push_back(d);
    }
  }
  return ans;
}

string SpiralizeString(int n, int m, string s) {
  vector<string> a(n, string(m, ' '));

  while (s.size() < n * m) {
    s.push_back('0');
  }

  for (int x1 = 0, x2 = n - 1, y1 = 0, y2 = m - 1, z = 0; x1 <= x2 && y1 <= y2; ++x1, --x2, ++y1, --y2) {
    for (int y = y1; y <= y2; ++y) {
      a[x1][y] = s[z++];
    }

    for (int x = x1 + 1; x <= x2; ++x) {
      a[x][y2] = s[z++];
    }

    if (x2 != x1) {
      for (int y = y2 - 1; y >= y1; --y) {
        a[x2][y] = s[z++];
      }
    }

    if (y1 != y2) {
      for (int x = x2 - 1; x > x1; --x) {
        a[x][y1] = s[z++];
      }
    }
  }

  string ans;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      ans.push_back(a[x][y]);
    }
  }

  return ans;
}

string Solve() {
  string s;
  getline(cin, s);

  reverse(s.begin(), s.end());

  int n = ExtractNumber(s);
  int m = ExtractNumber(s);

  reverse(s.begin(), s.end());

  return SpiralizeString(n, m, EncodeString(s));
}

int main() {
  string t_string;
  getline(cin, t_string);
  int t = stoi(t_string);
  for (int k = 1; k <= t; ++k) {
    printf("%d %s\n", k, Solve().c_str());
  }
  return 0;
}