#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 20
#define MOD 1000000007

int a[N], c[N], p2[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    if(a[i] == 0)
      continue;

    int k;
    for(k = B - 1; k > -1 && (a[i] & (1 << k)) == 0; --k);

    for(int j = i + 1; j <= n; ++j){
      if((a[j] & (1 << k)) > 0)
        a[j] ^= a[i];
    }

    c[i] = k;
  }

  p2[0] = 1;
  for(int i = 1; i < N; ++i)
    p2[i] = (2ll * p2[i - 1]) % MOD;

  vector<int> b;
  for(int i = 1; i <= n; ++i){
    if(a[i]){
      b.PB(i);
    }
  }

  while(q--){
    int l, x, k = 0;
    scanf("%d%d", &l, &x);

    for(auto i : b){
      if(i > l)
        break;
      if((x & (1 << c[i])) > 0)
        x ^= a[i];
      ++k;
    }

    int ans = (x == 0) ? p2[l - k] : 0;
    printf("%d\n", ans);
  }

  return 0;
}
