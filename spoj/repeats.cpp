#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50002
#define P 31

char s[N];
uint p[N], h[N];

void Initialize() {
  p[0] = 1;
  for (int i = 1; i < N; ++i) {
    p[i] = p[i - 1] * P;
  }
}

void PreProcess(int n) {
  h[n + 1] = 0;
  for (int i = n; i > 0; --i) {
    h[i] = h[i + 1] * P + (s[i - 1] - 'a' + 1);
  }
}

uint GetHash(int len, int i) {
  return h[i] - h[i + len] * p[len];
}

bool AreSubstringEqual(int n, int len, int i, int j) {
  if (max(i, j) + len - 1 > n) {
    return false;
  }
  return GetHash(len, i) == GetHash(len, j);
}

int LongestCommonPrefixLength(int n, int i, int j) {
  if (i <= 0 || j <= 0 || i > n || j > n) {
    return 0;
  }

  int x = 0, y = n - max(i, j) + 1, ans = 0;
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (AreSubstringEqual(n, mid, i, j)) {
      ans = mid;
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  return ans;
}

int LongestCommonSuffixLength(int n, int i, int j) {
  if (i <= 0 || j <= 0 || i > n || j > n) {
    return 0;
  }

  int x = 0, y = min(i, j), ans = 0;
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (AreSubstringEqual(n, mid, i - mid + 1, j - mid + 1)) {
      ans = mid;
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  return ans;
}

int Compute(int n, int len) {
  int ans = 0;
  for (int i = 1; i + len * (ans + 1) - 1 <= n;) {
    int j = i, k = 0;

    while (AreSubstringEqual(n, len, i, j)) {
      j += len;
      ++k;
    }

    int longest_common_prefix_length = LongestCommonPrefixLength(n, i, j);
    int longest_common_suffix_length = LongestCommonSuffixLength(n, i - 1, j - 1);

    if (longest_common_prefix_length + longest_common_suffix_length >= len) {
      ++k;
    }

    ans = max(ans, k);
    i = j;
  }
  return ans;
}

int Solve() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    getchar();
    s[i] = getchar();
  }
  s[n] = '\0';

  PreProcess(n);

  int ans = 1;
  for (int i = 0, cnt = 1; i < n; ++i) {
    if (i > 0 && s[i] == s[i - 1]) {
      ++cnt;
    } else {
      cnt = 1;
    }
    ans = max(ans, cnt);
  }

  for (int len = 2; len * (ans + 1) <= n; ++len) {
    ans = max(ans, Compute(n, len));
  }

  return ans;
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}