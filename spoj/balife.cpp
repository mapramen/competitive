#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 9001

ll a[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i];
  }

  if(s % n != 0){
    return -1;
  }

  s /= n;

  ll ans = 0;
  for(ll ansx = 0, i = 1; i <= n; ++i){
    ansx += (a[i] - s);
    ans = max(ans, abs(ansx));
  }

  for(ll ansx = 0, i = n; i != 0; --i){
    ansx += (a[i] - s);
    ans = max(ans, abs(ansx));
  }

  return ans;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}