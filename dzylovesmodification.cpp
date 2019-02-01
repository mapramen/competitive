#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define K 1000001

ll r[N], c[N], a[K], b[K];

void Compute(int n, int m, int k, int p, ll a[N], ll s[K]){
  priority_queue<ll> Q;

  for(int i = 1; i <= n; i++)
    Q.push(a[i]);

  for(int i = 1; i <= k; i++){
    s[i] = Q.top();
    Q.pop();
    Q.push(s[i] - m * p);
    s[i] += s[i - 1];
  }
}

int main(){
  int n, m, k, p;
  ll ans = LLONG_MIN;

  scanf("%d%d%d%d", &n, &m, &k, &p);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int a;
      scanf("%d", &a);
      r[i] += a;
      c[j] += a;
    }
  }

  Compute(n, m, k, p, r, a);
  Compute(m, n, k, p, c, b);

  for(int i = 0; i <= k; i++){
    ll ansx = a[i] + b[k - i] - 1ll * i * (k - i) * p;
    ans = max(ans, ansx);
  }

  printf("%lld\n", ans);

  return 0;
}
