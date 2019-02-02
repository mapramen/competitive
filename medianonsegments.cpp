#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200005

int a[N], c[2 * N];

ll MedianGE(int n, int m){
  for(int i = 0; i < 2 * N; ++i){
    c[i] = 0;
  }

  int k = N;
  ll ans = 0;

  c[k] = 1;
  for(int i = 1, s = 1; i <= n; ++i){
    int j = (a[i] < m) ? -1 : 1;
    s += (1 + ((a[i] < m) ? -c[k] : c[k + 1]));
    k += j;
    ++c[k];
    ans += (s - c[k]);
  }

  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = MedianGE(n, m) - MedianGE(n, m + 1);

  printf("%lld\n", ans);

  return 0;
}
