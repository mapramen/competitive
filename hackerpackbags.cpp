#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

pii l[N], r[N];
int c[N], d[N];

int main(){
  int n, x, ans = INT_MAX;
  map< int, int > m;

  scanf("%d%d", &n, &x);
  for(int i = 1; i <= n; i++){
    scanf("%d%d%d", &l[i].first, &r[i].first, &c[i]);
    l[i].second = r[i].second = i;
    d[i] = r[i].first - l[i].first + 1;
  }

  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);

  for(int i = 1, j = 1; i <= n; i++){
    for( ; j <= n && r[j].first < l[i].first; j++){
      int k = r[j].second, cost = c[k], t = d[k];
      if(m.find(t) == m.end())
        m[t] = cost;
      else
        m[t] = min(m[t], cost);
    }
    int t = x - d[l[i].second];
    if(m.find(t) != m.end()){
      int ansx = m[t] + c[l[i].second];
      ans = min(ans, ansx);
    }
  }

  if(ans == INT_MAX)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
