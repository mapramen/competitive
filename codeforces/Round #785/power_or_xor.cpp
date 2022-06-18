#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 20
#define N (1 << B)

int b[N + 1], ans[N];

bool Parity(int n, int r){
  if(r < 0 || n < r){
    return false;
  }
  return (n == r) || (((n - 1) | (r - 1)) == n - 1);
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 1; i <= n; ++i){
    ll x = 1;
    for(int j = i; j <= n; ++j){
      if(j == i){
        x *= b[j];
      }
      else{
        if(b[j] >= B){
          break;
        }
        x *= (1 << b[j]);
      }

      if(x >= N){
        break;
      }

      int z = ((int)(i != 1)) + ((int)(j != n));
      if(Parity(n - 1 - (j - i + z), max(0, k - z))){
        ans[x] ^= 1;
      }
    }
  }

  int i = N - 1;
  for( ; i != 0 && ans[i] == 0; --i);

  for( ; i != -1; --i){
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;
}