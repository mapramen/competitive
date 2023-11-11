#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ManacherAlgorithmOddLength(string s) {
  const int n = s.size();
  vector<int> palindrome_widths(n);

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

    palindrome_widths[i] = k;
  }

  return palindrome_widths;
}

pii ManacherAlgorithm(string s) {
  string t = "#";
  for (char c : s) {
    t.push_back(c);
    t.push_back('#');
  }

  int longest_palindrome_length = 0;
  int longest_palindrome_length_cnt = 0;

  vector<int> palindrome_widths = ManacherAlgorithmOddLength(t);
  for (int i = 0; i < t.size(); ++i) {
    int palindrome_length = palindrome_widths[i];
    if (palindrome_length > longest_palindrome_length) {
      longest_palindrome_length = palindrome_length;
      longest_palindrome_length_cnt = 1;
    } else if (palindrome_length == longest_palindrome_length) {
      ++longest_palindrome_length_cnt;
    }
  }

  return {longest_palindrome_length, longest_palindrome_length_cnt};
}

pii Solve() {
  string s;
  cin >> s;
  return ManacherAlgorithm(s);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [longest_palindrome_length, longest_palindrome_length_cnt] = Solve();
    printf("%d %d\n", longest_palindrome_length, longest_palindrome_length_cnt);
  }
  return 0;
}