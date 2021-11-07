#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 9
#define N (1 << B)

int a[N], b[N];

int main(){
  a[0] = 0;
  for(int i = 1; i < N; ++i){
    a[i] = INT_MAX;
  }

  int n;
  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);

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
      a[i] = min(a[i], b[i]);
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