#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 13
#define N (1 << B)

int a[N], b[N];
int lastOccur[N];

int main(){
  for(int i = 1; i < N; ++i){
    a[i] = INT_MAX;
    lastOccur[i] = INT_MAX;
  }

  a[0] = 0;

  int n;
  scanf("%d", &n);

  int lastUpdate = n;
  while(n--){
    int x;
    scanf("%d", &x);

    if(lastUpdate >= lastOccur[x]){
      lastOccur[x] = n;
      continue;
    }

    lastOccur[x] = n;

    for(int i = 0; i < N; ++i){
      b[i] = INT_MAX;
    }

    for(int y = 0; y < N; ++y){
      if(a[y] >= x){
        continue;
      }
      b[(x ^ y)] = x;
    }

    for(int i = 0; i < N; ++i){
      if(b[i] < a[i]){
        a[i] = b[i];
        lastUpdate = n;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; ++i){
    ans += a[i] != INT_MAX;
  }

  printf("%d\n", ans);
  for(int i = 0; i < N; ++i){
    if(a[i] != INT_MAX){
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}