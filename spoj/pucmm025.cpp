#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 501

char s[N];

int GetCount(int digit) {
  int cnt = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    cnt += (s[i] - '0' == digit);
  }
  return cnt;
}

bool IsDivisible(int digit) {
  int rem = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    rem = (rem * 10 + s[i] - '0') % digit;
  }
  return rem == 0;
}

int Solve() {
  if (scanf("%s", s) == EOF) {
    exit(0);
  }

  int cnt = 0;
  for (int digit = 1; digit <= 9; ++digit) {
    int digit_cnt = GetCount(digit);
    if (digit_cnt == 0) {
      continue;
    }
    cnt += IsDivisible(digit) ? digit_cnt : 0;
  }
  return cnt;
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}