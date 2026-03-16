#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsValid(string& s) {
  int i = s.size() - 1;
  while (i > -1 && s[i] != 'A') {
    --i;
  }

  while (i > -1 && s[i] != 'B') {
    --i;
  }

  return i == -1;
}

void Operate(string& s, int i, int j) {
  swap(s[i], s[j]);
  swap(s[i + 1], s[j + 1]);
}

void CheckAndPush(map<string, string>& parent, queue<string>& Q, string t, string s) {
  if (parent.find(t) == parent.end()) {
    parent[t] = s;
    Q.push(t);
  }
}

vector<string> Brute(string s) {
  int n = s.size();
  queue<string> Q;
  map<string, string> parent;

  CheckAndPush(parent, Q, s, "");

  while (!Q.empty()) {
    s = Q.front();
    Q.pop();

    if (IsValid(s)) {
      vector<string> ans;
      while (s != "") {
        ans.push_back(s);
        s = parent[s];
      }
      ans.pop_back();
      reverse(ans.begin(), ans.end());
      return ans;
    }

    int k = 0;
    while (s[k] != '.') {
      ++k;
    }

    string t = s;
    for (int i = 0; i + 1 < n; ++i) {
      if (i == k - 1 || i == k || i == k + 1) {
        continue;
      }
      Operate(t, i, k);
      CheckAndPush(parent, Q, t, s);
      Operate(t, i, k);
    }
  }

  return vector<string>();
}

bool Solve(vector<string>& ans, string& s) {
  if (IsValid(s)) {
    return true;
  }

  int n = s.size();

  int i = 0;
  while (s[i] == 'A') {
    ++i;
  }

  if (s[i] == '.') {
    int j = i + 2;
    while (s[j] != 'A') {
      ++j;
    }

    if (j != n - 1) {
      Operate(s, i, j);
      ans.push_back(s);
      return Solve(ans, s);
    }

    Operate(s, i, i + 2);
    ans.push_back(s);
    return Solve(ans, s);
  }

  if (s[i + 1] == '.') {
    Operate(s, i + 1, i + 3);
    ans.push_back(s);
    return Solve(ans, s);
  }

  if (s[i + 1] == 'A' || s[i + 2] != '.') {
    int j = i + 2;
    while (s[j] != '.') {
      ++j;
    }

    Operate(s, i, j);
    ans.push_back(s);
    return Solve(ans, s);
  }

  int j = i + 4;
  while (s[j] != 'A') {
    ++j;
  }

  if (j != n - 1) {
    Operate(s, i, i + 2);
    ans.push_back(s);
    return Solve(ans, s);
  }

  Operate(s, i + 2, n - 2);
  ans.push_back(s);

  Operate(s, i, n - 2);
  ans.push_back(s);

  Operate(s, i, i + 3);
  ans.push_back(s);
  return Solve(ans, s);
}

vector<string> Solve(string s) {
  if (s.size() < 10) {
    return Brute(s);
  }

  vector<string> ans;
  Solve(ans, s);
  return ans;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<string> ans = Solve(s);
  if (!IsValid(s) && ans.empty()) {
    printf("-1\n");
    return 0;
  }

  printf("%lu\n", ans.size());
  for (string& t : ans) {
    printf("%s\n", t.c_str());
  }

  return 0;
}