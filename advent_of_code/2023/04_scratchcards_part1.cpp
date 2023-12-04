#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ExtractNumbers(string& s) {
  vector<string> numbers;

  string t;
  while (!s.empty() && s.back() != '|') {
    char c = s.back();
    s.pop_back();

    if (isdigit(c)) {
      t.push_back(c);
    }

    if (!s.empty() && s.back() != '|' && isdigit(c)) {
      continue;
    }

    if (t.empty()) {
      continue;
    }

    numbers.push_back(t);
    t.clear();
  }

  if (!s.empty() && s.back() == '|') {
    s.pop_back();
  }

  return numbers;
}

set<string> ExtractWinningNumbers(string& s) {
  while (!s.empty() && s.back() != ':') {
    s.pop_back();
  }

  vector<string> numbers = ExtractNumbers(s);

  set<string> winning_numbers;
  for (string& number : numbers) {
    winning_numbers.insert(number);
  }

  return winning_numbers;
}

vector<string> ExtractScratchcardNumbers(string& s) {
  return ExtractNumbers(s);
}

int main() {
  long long ans = 0;

  string s;
  while (getline(cin, s)) {
    reverse(s.begin(), s.end());

    set<string> winning_numbers = ExtractWinningNumbers(s);
    vector<string> scratchcard_numbers = ExtractScratchcardNumbers(s);

    ll ansx = 0;
    for (string& number : scratchcard_numbers) {
      if (winning_numbers.find(number) == winning_numbers.end()) {
        continue;
      }

      if (ansx == 0) {
        ansx = 1;
      } else {
        ansx *= 2;
      }
    }
    ans += ansx;
  }

  cout << ans << endl;

  return 0;
}