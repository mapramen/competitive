#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int games_completed = 0, sum_of_distinct_words_in_a_game = 0;

  string s;
  set<string> distinct_words;
  while (cin >> s) {
    string t;
    reverse(s.begin(), s.end());

    while (!s.empty()) {
      char c = s.back();
      s.pop_back();

      if (isalpha(c)) {
        t.push_back(tolower(c));
      }

      if (isalpha(c) && !s.empty()) {
        continue;
      }

      if (t.empty()) {
        continue;
      }

      if (t != "bullshit") {
        distinct_words.insert(t);
      } else {
        ++games_completed;
        sum_of_distinct_words_in_a_game += distinct_words.size();
        distinct_words.clear();
      }

      t.clear();
    }
  }

  int g = __gcd(sum_of_distinct_words_in_a_game, games_completed);
  printf("%d / %d\n", sum_of_distinct_words_in_a_game / g, games_completed / g);

  return 0;
}