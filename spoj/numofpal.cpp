#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ManacherAlgorithmOddLength(string s) {
  const int n = s.size();
  int ans = 0;

  vector<int> d(n);
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

    while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
      ++k;
    }

    d[i] = k--;
    if (i + k > r) {
      l = i - k, r = i + k;
    }

    ans += d[i] / 2;
  }

  return ans;
}

int ManacherAlgorithm(string s) {
  string t = "#";
  for (char c : s) {
    t.push_back(c);
    t.push_back('#');
  }
  return ManacherAlgorithmOddLength(t);
}

int main() {
  string s;
  cin >> s;
  cout << ManacherAlgorithm(s) << '\n';
  return 0;
}