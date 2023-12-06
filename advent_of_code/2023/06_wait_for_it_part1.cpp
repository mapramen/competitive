#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ExtractNumbers() {
  string s;
  getline(cin, s);
  reverse(s.begin(), s.end());

  vector<int> numbers;

  string t;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isdigit(c)) {
      t.push_back(c);
    }

    if (!s.empty() && isdigit(s.back()) || t.empty()) {
      continue;
    }

    int number = stoi(t);
    t.clear();

    numbers.push_back(number);
  }

  return numbers;
}

int main() {
  vector<int> times = ExtractNumbers();
  vector<int> distances = ExtractNumbers();

  ll ans = 1;
  for (int i = 0; i < times.size(); ++i) {
    int T = times[i], D = distances[i], cnt = 0;
    for (int t = 0; t <= T; ++t) {
      int d = t * (T - t);
      cnt += (D < d);
    }
    ans *= cnt;
  }

  cout << ans << endl;

  return 0;
}