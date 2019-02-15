#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int c[N], w[N], a[N], b[N];

int main(){
  int n, m;
  priority_queue< pii, vector< pii >, greater< pii > > Q;
  ll ans = 0;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  for(int i = 1; i <= n; i++)
    scanf("%d", &w[i]);

  for(int i = 1; i <= n; i++){
    a[i] = c[i] / 100;
    b[i] = c[i] %= 100;

    if(c[i] == 0)
      continue;

    if(c[i] <= m){
      m -= c[i];
      Q.push(MP(w[i] * (100 - c[i]), i));
    }
    else{
      int j = Q.empty() ? 0 : Q.top().second, k;

      if(Q.empty() || w[i] * (100 - c[i]) <= w[j] * (100 - c[j]))
        k = i;
      else{
        Q.pop();
        k = j;
        Q.push(MP(w[i] * (100 - c[i]), i));
      }

      m += (100 - c[i]);
      a[k]++, b[k] = 0;
      ans += w[k] * (100 - c[k]);
    }
  }

  printf("%lld\n", ans);
  for(int i = 1; i <= n; i++)
    printf("%d %d\n", a[i], b[i]);

  return 0;
}
