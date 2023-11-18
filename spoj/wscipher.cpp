#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 3

int GetGroupNumber(char c) {
  if ('a' <= c && c <= 'i') {
    return 0;
  }

  if ('j' <= c && c <= 'r') {
    return 1;
  }

  return 2;
}

string Solve() {
  int k[B];

  for (int i = 0; i < B; ++i) {
    scanf("%d", &k[i]);
  }

  bool all_zeros = true;
  for (int i = 0; i < B; ++i) {
    if (k[i] != 0) {
      all_zeros = false;
      break;
    }
  }

  if (all_zeros) {
    exit(0);
  }

  string s;
  cin >> s;

  vector<vector<char>> groups(B);
  for (char c : s) {
    groups[GetGroupNumber(c)].push_back(c);
  }

  for (int i = 0; i < B; ++i) {
    if (groups[i].size() == 0) {
      continue;
    }

    int n = groups[i].size();
    k[i] %= n;

    groups[i].insert(groups[i].end(), groups[i].begin(), groups[i].begin() + n - k[i]);
    reverse(groups[i].begin(), groups[i].end());
    groups[i].resize(n);
  }

  for (char& c : s) {
    int i = GetGroupNumber(c);
    c = groups[i].back();
    groups[i].pop_back();
  }

  return s;
}

int main() {
  while (true) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}