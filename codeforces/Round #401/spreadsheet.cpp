#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define inf INT_MAX
#define N 100001

int a[N], b[N], c[N];

int main(){
  int n, m, q;

  scanf("%d%d", &n, &m);

  for(int j = 1; j <= m; j++)
    a[j] = inf;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int x;
      scanf("%d", &x);
      if(a[j] <= x)
        b[j]++;
      else
        b[j] = 0;
      a[j] = x;
      c[i] = max(c[i], b[j]);
    }
  }

  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    if(c[r] >= r - l)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
