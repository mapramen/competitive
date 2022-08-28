#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    ans += (a[i] / k);
    a[i] %= k;
  }
  sort(a + 1, a + n + 1);

  for(int x = 1, y = n; x < y; ){
    if(a[x] + a[y] < k){
      ++x;
      continue;
    }
    ++ans, ++x, --y;
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