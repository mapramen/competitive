#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ExtractNumber(string& s) {
  while (!s.empty() && !isdigit(s.back())) {
    s.pop_back();
  }

  string t;
  while (!s.empty() && isdigit(s.back())) {
    t.push_back(s.back());
    s.pop_back();
  }

  return stoi(t);
}

string ExtractWord(string& s) {
  string color;

  for (; !s.empty() && s.back() != ',' && s.back() != ';'; s.pop_back()) {
    if (!isalpha(s.back())) {
      continue;
    }
    color.push_back(tolower(s.back()));
  }

  return color;
}

int ExtractGameId(string& s) {
  return ExtractNumber(s);
}

tuple<int, int, int> ExtractBallCounts(string& s) {
  map<string, int> cnts;

  while (!s.empty() && s.back() != ';') {
    int cnt = ExtractNumber(s);
    string color = ExtractWord(s);
    cnts[color] = cnt;
  }

  if (!s.empty()) {
    s.pop_back();
  }

  return {cnts["red"], cnts["green"], cnts["blue"]};
}

int main() {
  long long ans = 0;

  string s;
  while (getline(cin, s)) {
    reverse(s.begin(), s.end());

    int game_id = ExtractGameId(s);

    int min_red = 0, min_green = 0, min_blue = 0;
    while (!s.empty()) {
      auto [red, green, blue] = ExtractBallCounts(s);
      min_red = max(min_red, red);
      min_green = max(min_green, green);
      min_blue = max(min_blue, blue);
    }
    ans += 1ll * min_red * min_green * min_blue;
  }

  cout << ans << endl;

  return 0;
}