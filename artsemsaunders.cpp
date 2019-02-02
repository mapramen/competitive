#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int f[N], g[N], h[N], inv_h[N];

int main(){
  int n, m = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &f[i]);
    if(inv_h[f[i]] == 0){
      inv_h[f[i]] = ++m;
      h[inv_h[f[i]]] = f[i];
    }
    g[i] = inv_h[f[i]];
  }

  for(int i = 1; i <= m; i++)
    if(g[h[i]] != i)
      m = -1;

  for(int i = 1; i <= n; i++)
    if(h[g[i]] != f[i])
      m = -1;

  printf("%d\n", m);

  if(m > 0){
    for(int i = 1; i <= n; i++)
      printf("%d ", g[i]);
    printf("\n");

    for(int i = 1; i <= m; i++)
      printf("%d ", h[i]);
    printf("\n");
  }
  
  return 0;
}
