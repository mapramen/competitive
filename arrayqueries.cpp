#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define SQRTN 320

int a[N], T[SQRTN][N];

int main(){
  int n, q;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int p = n; p > 0; p--){
    for(int k = 1; k < SQRTN; k++){
      int j = p + a[p] + k;
      if(j > n)
        T[k][p] = 1;
      else
        T[k][p] = 1 + T[k][j];
    }
  }

  scanf("%d", &q);
  while(q--){
    int p, k, ans = 0;
    scanf("%d%d", &p, &k);

    if(k < SQRTN)
      ans = T[k][p];
    else{
      while(p <= n){
        ans++;
        p += a[p] + k;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
