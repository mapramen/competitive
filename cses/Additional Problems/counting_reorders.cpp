// https://math.stackexchange.com/questions/4572019/arrangements-of-a-a-b-b-b-c-c-c-c-in-which-no-two-consecutive-letters-are-the
// https://math.stackexchange.com/questions/129451/find-the-number-of-arrangements-of-k-mbox-1s-k-mbox-2s-cdots/129802#129802
// Such problems become intractable very rapidly, I prefer to use a form of the generalized Laguerre polynomial as described by Jair Taylor

// Define polynomials for k≥1
//  by qk(x)=∑ki=1(−1)i−ki!(k−1i−1)xi
// .

// The number of permutations will be given by

// ∫∞0∏jqkj(x)e−xdx.

// We get q2(x)=(x2−2x)/2!

// q3(x)=(x3−6x2+6x)/3!

// q4(x)=(x4−12x2+36x2−24x)/4!

// Using the above method, I get an answer of 79

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001
#define B 26
#define MOD 1000000007

int fact[N], inv_fact[N];

int ModularExponentation(int a, int n) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a) {
  return ModularExponentation(a, MOD - 2);
}

void Initialize() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for (int i = N - 2; i > -1; --i) {
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nCr(int n, int r) {
  if (n < 0 || r < 0 || n < r) {
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

vector<int> GetQPolynomial(int k) {
  vector<int> q(k + 1);
  for (int i = k, minus_one_power = 0; i > 0; --i, minus_one_power ^= 1) {
    int qi = (1ll * nCr(k - 1, i - 1) * inv_fact[i]) % MOD;
    if (minus_one_power == 1) {
      qi = (MOD - qi) % MOD;
    }
    q[i] = qi;
  }
  return q;
}

vector<int> MultiplyPolynomials(const vector<int>& a, const vector<int>& b) {
  int n = a.size(), m = b.size();
  vector<int> c(n + m - 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0, k = i + j; j < m; ++j, ++k) {
      c[k] = (c[k] + (1ll * a[i] * b[j]) % MOD) % MOD;
    }
  }
  return c;
}

int main() {
  string s;
  cin >> s;

  Initialize();

  vector<int> cnt(B);
  for (char c : s) {
    ++cnt[c - 'a'];
  }

  vector<int> Q = vector<int>(1, 1);
  for (int k : cnt) {
    if (k == 0) {
      continue;
    }
    vector<int> q = GetQPolynomial(k);
    Q = MultiplyPolynomials(Q, q);
  }

  int ans = 0;
  for (int i = 0; i < Q.size(); ++i) {
    ans = (ans + 1ll * fact[i] * Q[i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}