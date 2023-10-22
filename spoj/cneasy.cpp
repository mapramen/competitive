#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101
#define M 360

char s[N];

int Solve() {
  int n;
  scanf("%d", &n);

  vector<double> a;
  while (n--) {
    double angle;
    scanf("%s%lf", s, &angle);
    a.push_back(angle);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  double ans = a.back() - a.front();
  for (int i = 0; i < a.size(); ++i) {
    int j = (i + 1) % a.size();
    ans = min(ans, M + a[i] - a[j]);
  }

  if (a.size() == 2) {
    ans = min(ans, M - ans);
  }

  return ceil(ans * 12);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}