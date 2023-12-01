#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pair<int, string>> digit_and_spelling_pairs = {
    {1, "1"},
    {1, "one"},
    {2, "2"},
    {2, "two"},
    {3, "3"},
    {3, "three"},
    {4, "4"},
    {4, "four"},
    {5, "5"},
    {5, "five"},
    {6, "6"},
    {6, "six"},
    {7, "7"},
    {7, "seven"},
    {8, "8"},
    {8, "eight"},
    {9, "9"},
    {9, "nine"},
};

int main() {
  long long ans = 0;

  string s;
  while (getline(cin, s)) {
    int first_digit = -1, last_digit = -1;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
      for (auto [digit, spelling] : digit_and_spelling_pairs) {
        string t;
        for (int j = i, k = 0; j < n && k < spelling.size(); ++j, ++k) {
          t.push_back(tolower(s[j]));
        }

        if (t != spelling) {
          continue;
        }

        if (first_digit == -1) {
          first_digit = digit;
        }

        last_digit = digit;
      }
    }

    ans += (10 * first_digit + last_digit);
  }

  cout << ans << endl;

  return 0;
}