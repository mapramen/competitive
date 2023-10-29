#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ManacherAlgorithmOddLength(string s, int palindrome_length) {
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

    if (palindrome_length % 2 == 0 && s[i] == '#' && palindrome_length < d[i]) {
      ++ans;
    }

    if (palindrome_length % 2 == 1 && s[i] != '#' && palindrome_length < d[i]) {
      ++ans;
    }
  }

  return ans;
}

int ManacherAlgorithm(string s, int palindrome_length) {
  string t = "#";
  for (char c : s) {
    t.push_back(c);
    t.push_back('#');
  }
  return ManacherAlgorithmOddLength(t, palindrome_length);
}

int main() {
  int palindrome_length;
  string s;
  cin >> palindrome_length >> s;
  cout << ManacherAlgorithm(s, palindrome_length) << '\n';
  return 0;
}