#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 20001

int parent[N];

int Find(int i) {
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i == 0 || j == 0 || i == j) {
    return false;
  }

  if (i > j) {
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

int main() {
  int q;
  scanf("%d", &q);

  int ans = 0;
  while (q--) {
    int i;
    scanf("%d", &i);

    parent[i] = i;
    ++ans;

    ans -= Union(i, i - 1);
    ans -= Union(i, i + 1);

    printf("%d\n", ans);
  }

  printf("Justice\n");

  return 0;
}