#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001
#define P 1000003
#define INVP 486802543
#define MOD 1000000007

char s[N + 1];
int p[N], invp[N];
int h[N], revh[N];

void Initialize() {
  p[0] = 1, invp[0] = 1;
  for (int i = 1; i < N; ++i) {
    p[i] = (1LL * p[i - 1] * P) % MOD;
    invp[i] = (1LL * invp[i - 1] * INVP) % MOD;
  }
}

void Update(int T[], int i, int x) {
  for (; i < N; i += (i & -i)) {
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int T[], int i) {
  int ans = 0;
  for (; i > 0; i -= (i & -i)) {
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

void Update(int n, int i, char c) {
  int x = c - s[i];
  Update(h, i, (1LL * p[i] * x) % MOD);
  Update(revh, n - i + 1, (1LL * p[n - i + 1] * x) % MOD);
  s[i] = c;
}

int Query(int T[], int i, int j) {
  return (Query(T, j) - Query(T, i - 1) + MOD) % MOD;
}

int QueryHash(int h[], int i, int j) {
  int ans = Query(h, i, j);
  ans = (1LL * ans * invp[i]) % MOD;
  return ans;
}

int main() {
  Initialize();

  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    char c = s[i];
    s[i] = 'a' - 1;
    Update(n, i, c);
  }

  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int i;
      char c;
      scanf("%d %c", &i, &c);
      Update(n, i, c);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%s\n", QueryHash(h, l, r) == QueryHash(revh, n - r + 1, n - l + 1) ? "YES" : "NO");
    }
  }

  return 0;
}