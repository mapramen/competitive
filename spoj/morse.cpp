#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

unordered_map<char, string> morse_code_mapping = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
};

unordered_map<string, int> ReadDictionary() {
  int n;
  cin >> n;

  unordered_map<string, int> dictionary;
  while (n--) {
    string s;
    cin >> s;

    string t;
    for (char c : s) {
      for (char d : morse_code_mapping[c]) {
        t.push_back(d);
      }
    }
    reverse(t.begin(), t.end());
    ++dictionary[t];
  }

  return dictionary;
}

int Solve() {
  string s;
  cin >> s;

  unordered_map<string, int> dictionary = ReadDictionary();

  int n = s.size();
  vector<int> dp(n + 1, 0);

  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int ans = 0;

    string t;
    for (int j = i, len = 1; len <= 80 && j > 0; --j, ++len) {
      t.push_back(s[j - 1]);
      auto it = dictionary.find(t);
      if (it == dictionary.end()) {
        continue;
      }
      ans += dp[j - 1] * it->second;
    }

    dp[i] = ans;
  }

  return dp[n];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}