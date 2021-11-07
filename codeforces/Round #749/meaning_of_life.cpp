#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N];

int Query(int n, int x, int y){
  printf("? ");
  for(int i = 1; i < n; ++i){
    printf("%d ", x);
  }
  printf("%d\n", y);
  fflush(stdout);

  int k;
  scanf("%d", &k);

  return k;
}

int main(){
  int n;
  scanf("%d", &n);

  int c = 0;
  for(int y = 2; y <= n; ++y){
    c += (Query(n, 1, y) != 0);
  }

  int x = n - c;
  a[n] = x;
  for(int y = 1; y <= n; ++y){
    if(y == x){
      continue;
    }
    a[Query(n, x, y)] = y;
  }

  printf("! ");
  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
  fflush(stdout);
  
  return 0;
}