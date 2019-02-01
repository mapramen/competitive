#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector< pii > > arrivals(N), departures(N);
ll c[N], prefix[N + 1], suffix[N + 1];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    int d, f, t, c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    if(f)
      arrivals[d].PB(MP(f, c));
    else
      departures[d].PB(MP(t, c));
  }

  ll inf = 2ll * n * N;

  prefix[0] = suffix[N] = n * inf;

  for(int i = 1; i <= n; ++i)
    c[i] = inf;

  for(int i = 1; i <= N; ++i){
    prefix[i] = prefix[i - 1];
    for(auto p : arrivals[i]){
      int a, b;
      tie(a, b) = p;
      if(b < c[a]){
        prefix[i] += (b - c[a]);
        c[a] = b;
      }
    }
  }

  for(int i = 1; i <= n; ++i)
    c[i] = inf;

  for(int i = N - 1; i > 0; --i){
    suffix[i] = suffix[i + 1];
    for(auto p : departures[i]){
      int a, b;
      tie(a, b) = p;
      if(b < c[a]){
        suffix[i] += (b - c[a]);
        c[a] = b;
      }
    }
  }

  ll ans = inf;

  for(int i = 1; i + k <= N; ++i)
    ans = min(ans, prefix[i - 1] + suffix[i + k]);

  if(ans >= inf)
    ans = -1;

  printf("%lld\n", ans);

  return 0;
}
