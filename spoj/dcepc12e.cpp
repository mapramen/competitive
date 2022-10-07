#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char op[10];
int a[N][N], b[N][N];
ll A[N], B[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &b[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      A[j] += a[i][j], B[i] += b[i][j];
    }
  }

  ll ans = 0;
  for(int k = 1; k <= n; ++k){
    ans += A[k] * B[k];
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int i, j, x;
    scanf("%s%d%d%d", op, &i, &j, &x);
    ++i, ++j;

    if(op[0] == 'A'){
      x -= a[i][j];
      ans += x * B[j];
      A[j] += x, a[i][j] += x;
    }
    else{
      x -= b[i][j];
      ans += A[i] * x;
      B[i] += x, b[i][j] += x;
    }

    printf("%lld\n", ans);
  }

  return 0;
}