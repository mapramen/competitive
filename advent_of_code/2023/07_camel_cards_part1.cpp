#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

char MapToOrderedChar(char c) {
  if (isdigit(c)) {
    return c - 1;
  }

  if (c == 'T') {
    return '9';
  }

  if (c == 'J') {
    return '0' + 10;
  }

  if (c == 'Q') {
    return '0' + 11;
  }

  if (c == 'K') {
    return '0' + 12;
  }

  if (c == 'A') {
    return '0' + 13;
  }

  return c;
}

string GetOrderedString(string s) {
  string t;
  for (char c : s) {
    t.push_back(MapToOrderedChar(c));
  }
  return t;
}

bool IsCountPresent(map<char, int>& C, int cnt) {
  for (auto [_, v] : C) {
    if (v == cnt) {
      return true;
    }
  }
  return false;
}

int GetType(string& s) {
  map<char, int> C;
  for (char c : s) {
    ++C[c];
  }

  if (IsCountPresent(C, 5)) {
    return 6;
  }

  if (IsCountPresent(C, 4)) {
    return 5;
  }

  if (C.size() == 2) {
    return 4;
  }

  if (IsCountPresent(C, 3)) {
    return 3;
  }

  if (C.size() == 3) {
    return 2;
  }

  if (C.size() == 4) {
    return 1;
  }

  return 0;
}

int main() {
  vector<tuple<int, string, int>> a;

  while (true) {
    string s;
    int bid;
    if (!(cin >> s >> bid)) {
      break;
    }
    string t = GetOrderedString(s);
    a.push_back({GetType(t), t, bid});
  }

  sort(a.begin(), a.end());

  ll ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    ans += 1ll * (i + 1) * get<2>(a[i]);
  }

  cout << ans << endl;

  return 0;
}