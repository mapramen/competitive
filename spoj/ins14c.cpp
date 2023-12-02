#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  vector<vector<int>> V(2);

  for (int i = n - 1; i > -1; --i) {
    V[s[i] - '0'].push_back(i);
  }

  for (int kx = 1, i = 0, j = 0; kx <= n - k; ++kx) {
    if (!V[kx % 2].empty()) {
      V[kx % 2].pop_back();
    } else {
      V[(kx + 1) % 2].pop_back();
    }
  }

  string ans;
  while (!V[0].empty() || !V[1].empty()) {
    if (V[0].empty() || (!V[1].empty() && V[1].back() < V[0].back())) {
      ans.push_back('1');
      V[1].pop_back();
    } else {
      ans.push_back('0');
      V[0].pop_back();
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}