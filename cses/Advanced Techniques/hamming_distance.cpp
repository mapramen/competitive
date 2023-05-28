#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 31

char s[B];

bool AreAnyEqual(vector<int>& a) {
  sort(a.begin(), a.end());
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i - 1]) {
      return true;
    }
  }
  return false;
}

int MinimumHammingDistance(vector<int>& a) {
  if (a.size() < 2) {
    return B;
  }

  if (AreAnyEqual(a)) {
    return 0;
  }

  vector<int> odd, even;
  for (int& x : a) {
    if (x % 2 == 1) {
      odd.push_back(x / 2);
    } else {
      even.push_back(x / 2);
    }
    x /= 2;
  }

  return min(1 + MinimumHammingDistance(a), min(MinimumHammingDistance(odd), MinimumHammingDistance(even)));
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    a[i] = strtol(s, NULL, 2);
  }

  printf("%d\n", MinimumHammingDistance(a));

  return 0;
}