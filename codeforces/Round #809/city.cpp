#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], b[N];
ll prefix[N], suffix[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n - 2; ++i){
    b[i] = max(0, 1 + max(a[i], a[i + 2]) - a[i + 1]);
  }

  n -= 2;

  if(n % 2 == 1){
    ll ans = 0;
    for(int i = 1; i <= n; i += 2){
      ans += b[i];
    }
    return ans;
  }

  prefix[1] = b[1];
  for(int i = 2; i <= n; ++i){
    prefix[i] = b[i] + prefix[i - 2];
  }

  suffix[n] = b[n], suffix[n + 1] = 0;
  for(int i = n - 1; i != 0; --i){
    suffix[i] = b[i] + suffix[i + 2];
  }

  ll ans = min(prefix[n - 1], prefix[n]);
  for(int i = 1; i + 3 <= n; i += 2){
    ans = min(ans, prefix[i] + suffix[i + 3]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}