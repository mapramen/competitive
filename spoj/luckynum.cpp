#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tdata tuple<int, int, int, int>
#define N 10000
#define MAX_LEN 200

tdata parent[2][N];
queue<tdata> Q;

void Reset(int n) {
  while (!Q.empty()) {
    Q.pop();
  }

  for (int i = 0; i < n; ++i) {
    parent[0][i] = {INT_MAX, -1, INT_MAX, INT_MAX};
    parent[1][i] = {INT_MAX, -1, INT_MAX, INT_MAX};
  }
}

void CheckAndPush(int n, int len, int six_started, int remainder, int d) {
  if (len > MAX_LEN) {
    return;
  }

  int new_six_started = six_started | (d == 6);
  int new_remainder = (remainder * 10 + d) % n;

  if (get<0>(parent[new_six_started][new_remainder]) != INT_MAX) {
    return;
  }

  parent[new_six_started][new_remainder] = {len, six_started, remainder, d};
  Q.push({len, new_six_started, new_remainder, d});
}

string GenerateString(int len, int six_started) {
  string ans;
  for (int remainder = 0; len > 0; --len) {
    auto [_, prev_six_started, prev_remainder, d] = parent[six_started][remainder];
    ans.push_back('0' + d);
    six_started = prev_six_started;
    remainder = prev_remainder;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

string Solve() {
  int n;
  scanf("%d", &n);

  Reset(n);

  Q.push({0, 0, 0, 8});

  while (!Q.empty()) {
    auto [len, six_started, remainder, d] = Q.front();
    Q.pop();

    if (remainder == 0 && len > 0) {
      return GenerateString(len, six_started);
    }

    CheckAndPush(n, len + 1, six_started, remainder, 6);
    if (d == 8) {
      CheckAndPush(n, len + 1, six_started, remainder, 8);
    }
  }

  return "-1";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}