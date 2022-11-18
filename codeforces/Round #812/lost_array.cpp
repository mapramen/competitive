#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N (1 << 20)

int a[N];

void SubMaskSum(int n){
  for(int k = __builtin_ctz(n); k != -1; --k){
    for(int i = 0; i < n; ++i){
      if((i & (1 << k)) == 0){
        continue;
      }
      a[i] ^= a[(i ^ (1 << k))];
    }
  }
}

void SuperMaskSum(int n){
  reverse(a, a + n);
  SubMaskSum(n);
  reverse(a, a + n);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int m = 1;
  for( ; m < n; m *= 2);

  reverse(a, a + m);

  SuperMaskSum(m);

  for(int i = 0; i < m - n; ++i){
    a[i] = 0;
  }

  SuperMaskSum(m);

  SubMaskSum(m);

  reverse(a, a + n);

  for(int i = 0; i < n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}