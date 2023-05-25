#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ZFunction(string& s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }

    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

vector<int> PrefixFunction(string& s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    pi[i] = j;
  }
  return pi;
}

int main() {
  string s;
  cin >> s;

  for (int zi : ZFunction(s)) {
    cout << zi << " ";
  }
  cout << endl;

  for (int pi : PrefixFunction(s)) {
    cout << pi << " ";
  }
  cout << endl;

  return 0;
}