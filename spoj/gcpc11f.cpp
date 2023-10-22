#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 26

string Solve() {
  string s;
  getline(cin, s);

  vector<int> cnt(B, 0);
  for (char c : s) {
    if (!isalpha(c)) {
      continue;
    }
    ++cnt[c - 'A'];
  }

  int max_freq = *max_element(cnt.begin(), cnt.end());
  if (count(cnt.begin(), cnt.end(), max_freq) > 1) {
    return "NOT POSSIBLE";
  }

  int max_freq_char = max_element(cnt.begin(), cnt.end()) - cnt.begin();
  int shift = (max_freq_char - ('E' - 'A') + B) % B;

  for (char& c : s) {
    if (!isalpha(c)) {
      continue;
    }
    c = 'A' + (c - 'A' + B - shift) % B;
  }

  return to_string(shift) + " " + s;
}

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}