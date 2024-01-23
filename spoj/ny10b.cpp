#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Int2Vec(int b, int x) {
  vector<int> v;
  for (; x > 0; x /= b) {
    v.push_back(x % b);
  }

  if (v.empty()) {
    v.push_back(0);
  }

  return v;
}

int Calculate(int b, int x, int y) {
  vector<int> A = Int2Vec(b, x);
  vector<int> B = Int2Vec(b, y);

  int n = max(A.size(), B.size());
  A.resize(n);
  B.resize(n);

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans = ans * b + (A[i] + B[i]) % b;
  }

  return ans;
}

pii Solve() {
  int p, b, x, y;
  scanf("%d%d%d%d", &p, &b, &x, &y);
  return {p, Calculate(b, x, y)};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [n, ans] = Solve();
    printf("%d %d\n", n, ans);
  }
  return 0;
}