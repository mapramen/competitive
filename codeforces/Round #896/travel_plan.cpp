#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 998244353

int ModularExponentation(int a, ll n) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int Multiply(int a, int b) {
  return (1ll * a * b) % MOD;
}

struct Data {
  vector<int> C;
  vector<int> S;

  Data(vector<int>& C, vector<int>& S)
      : C(C), S(S) {}
};

Data GetNull() {
  vector<int> c(1, 1);
  vector<int> s(1, 1);
  return Data(c, s);
}

Data GetLeaf() {
  vector<int> c(2);
  vector<int> s(2);
  c[1] = 1, s[1] = 1;
  return Data(c, s);
}

Data Combine(Data& a, Data& b) {
  auto [C1, S1] = a;
  auto [C2, S2] = b;

  vector<int> C(1 + max(C1.size(), C2.size()));
  vector<int> S(max(C1.size() + C2.size(), max(S1.size(), S2.size())));

  C[1] = 1;

  for (int i = 1, k = 2; i < C1.size(); ++i, ++k) {
    C[k] = (C[k] + C1[i]) % MOD;
  }

  for (int j = 1, k = 2; j < C2.size(); ++j, ++k) {
    C[k] = (C[k] + C2[j]) % MOD;
  }

  for (int k = 0; k < C.size(); ++k) {
    S[k] = C[k];
  }

  for (int i = 0; i < S1.size(); ++i) {
    S[i] = (S[i] + S1[i]) % MOD;
  }

  for (int j = 0; j < S2.size(); ++j) {
    S[j] = (S[j] + S2[j]) % MOD;
  }

  for (int i = 0; i < C1.size(); ++i) {
    for (int j = 0, k = i + 1; j < C2.size(); ++j, ++k) {
      if (i == 0 || j == 0) {
        continue;
      }
      S[k] = (S[k] + Multiply(C1[i], C2[j])) % MOD;
    }
  }

  return Data(C, S);
}

vector<pair<ll, Data>> GetLeafLevel(ll n, int m) {
  ll x = 0;
  while (x < n) {
    x = 2 * x + 1;
  }
  x = (x - 1) / 2;

  ll y = x + 1;
  x = n - x;
  y = y - x;

  vector<pair<ll, Data>> ans;
  ans.push_back({x, GetLeaf()});

  if (y != 0) {
    ans.push_back({y, GetNull()});
  }

  return ans;
}

vector<pair<ll, Data>> GetParentLevel(vector<pair<ll, Data>>& a) {
  vector<pair<ll, Data>> ans;

  for (int i = 0; i < a.size(); ++i) {
    ll cnt = a[i].first / 2;
    a[i].first %= 2;

    if (cnt != 0) {
      ans.push_back({cnt, Combine(a[i].second, a[i].second)});
    }

    if (a[i].first == 1) {
      ans.push_back({1, Combine(a[i].second, a[i + 1].second)});
      --a[i + 1].first;
    }
  }

  return ans;
}

int Solve() {
  ll n;
  int m;
  scanf("%lld%d", &n, &m);

  vector<pair<ll, Data>> a = GetLeafLevel(n, m);

  while (a.size() > 1 || a.front().first != 1) {
    a = GetParentLevel(a);
  }

  vector<int> S = a.front().second.S;
  vector<int> P(S.size());

  for (int k = 1; k < m; ++k) {
    for (int t = 0, x = 1; t < S.size(); ++t, x = Multiply(x, k)) {
      P[t] = (P[t] + x) % MOD;
    }
  }

  int ans = 0;
  for (int t = 1; t < S.size(); ++t) {
    int ansx = Multiply(ModularExponentation(m, n - t), P[t]);
    ansx = (MOD + ModularExponentation(m, n + 1) - ansx) % MOD;
    ans = (ans + Multiply(ansx, S[t])) % MOD;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}