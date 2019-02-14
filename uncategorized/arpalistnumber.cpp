#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

ll c[2 * N], s[2 * N];
bool isPrime[2 * N];

ll GetCnt(int i, int j){
  return c[j] - c[i - 1];
}

ll GetSum(int i, int j){
  return s[j] - s[i - 1];
}

int main(){
  int n, x, y;
  ll ans = LLONG_MAX;

  scanf("%d%d%d", &n, &x, &y);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    s[j] += j;
    ++c[j];
  }

  n = 2;
  for(int i = 2; i < 2 * N; ++i){
    if(c[i])
      n = i;

    s[i] += s[i - 1], c[i] += c[i - 1];
    isPrime[i] = 1;
  }

  for(int g = 2; g <= n; ++g){
    if(isPrime[g] == 0)
      continue;

    ll ansx = 0;
    for(int i = 1, k = g; i <= n; i += g, k += g){
      int j = k - min(g - 1, x / y);
      ansx += (x * GetCnt(i, j - 1) + y * (GetCnt(j, k) * k - GetSum(j, k)));
    }

    ans = min(ans, ansx);

    for(int k = g + g; k <= n; k += g)
      if(isPrime[k] == 1)
        isPrime[k] = 0;
  }

  printf("%lld\n", ans);

  return 0;
}
