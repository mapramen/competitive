#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N (1 << 19)
#define MAXN 1000001

bool a[MAXN];

bool Check(int n, int x){
  for(int i = 0; i < MAXN; ++i){
    if(a[i] == 0)
      continue;
    --n;
    x ^= i;
  }
  if(n == 0 && x == 0){
    for(int i = 0; i < MAXN; ++i)
      if(a[i])
        printf("%d ", i);
    printf("\n");
    return 1;
  }
  return 0;
}

int main(){
  int n, x, y;

  scanf("%d%d", &n, &x);

  y = 0;
  for(int i = 0, j = N; i < n; ++i, ++j){
    y ^= j;
    a[j] = 1;
  }
  a[y] = 0;
  a[x] = 1;

  printf("YES\n");
  bool check = Check(n, x);

  if(check)
    return 0;

  for(int i = 0; i < MAXN; ++i)
    a[i] = 0;

  y = 0;
  for(int i = 0, j = N; i < n - 2; ++i, ++j){
    y ^= j;
    a[j] = 1;
  }
  a[(x ^ y)] = 1;
  a[0] = 1;

  check = Check(n, x);

  return 0;
}
