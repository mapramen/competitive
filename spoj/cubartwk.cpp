#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 21

vector<int> ReadArray(int n) {
  vector<int> cnt(N);
  while (n--) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  return cnt;
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n == 0 && m == 0) {
    exit(0);
  }

  vector<int> cnt1 = ReadArray(n);
  vector<int> cnt2 = ReadArray(m);

  int ans = 0;
  for (int i = 1; i < N; ++i) {
    ans += i * max(cnt1[i], cnt2[i]);
  }
  return ans;
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}