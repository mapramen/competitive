#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void PrintSet(set<int>& S) {
  printf("%lu ", S.size());
  for (int x : S) {
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
}

int Query(int u, int k, set<int>& S) {
  printf("? %d %d ", u, k);
  PrintSet(S);
  fflush(stdout);

  int res;
  scanf("%d", &res);
  return res;
}

void PrintAns(set<int>& S) {
  printf("! ");
  PrintSet(S);
  fflush(stdout);
}

pair<set<int>, set<int>> SplitIntoTwo(set<int>& S) {
  int n = S.size();
  int k = n / 2;

  set<int> A, B;
  for (int x : S) {
    if (k > 0) {
      A.insert(x);
      k--;
    } else {
      B.insert(x);
    }
  }

  return {A, B};
}

int GetNext(int n, int i) {
  set<int> S;
  for (int k = 1; k <= n; k++) {
    S.insert(k);
  }

  while (S.size() > 1) {
    auto [a, b] = SplitIntoTwo(S);

    if (Query(i, 1, a) == 1) {
      S = a;
    } else {
      S = b;
    }
  }

  return *S.begin();
}

int main() {
  int n;
  scanf("%d", &n);

  bool cycle_found = false;
  set<int> C{1};
  for (int k = 125, i = 1; k > 0; k--) {
    i = GetNext(n, i);
    if (C.count(i) != 0) {
      cycle_found = true;
      break;
    }

    C.insert(i);
  }

  for (int k = C.size(); !cycle_found; k *= 2) {
    for (int i = 1; i <= n; ++i) {
      if (C.count(i) != 0) {
        continue;
      }
      if (Query(i, k, C) == 1) {
        C.insert(i);
      }
    }
    cycle_found = C.size() < 2 * k;
  }

  for (int i = 1; i <= n; ++i) {
    if (C.count(i) != 0) {
      continue;
    }
    if (Query(i, n, C) == 1) {
      C.insert(i);
    }
  }

  PrintAns(C);

  return 0;
}