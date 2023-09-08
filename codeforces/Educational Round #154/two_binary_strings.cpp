#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  string A, B;
  cin >> A >> B;

  int n = A.size();
  for (int i = 0; i < n; ++i) {
    if (A[i] == '1' && B[i] == '1') {
      return true;
    }

    if (A[i] == '1') {
      swap(A, B);
    }

    int j = i;
    for (; j < n && B[j] == '1'; ++j)
      ;

    if (j == n) {
      return false;
    }

    for (; j >= i; --j) {
      B[j] = '0';
    }
  }

  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}