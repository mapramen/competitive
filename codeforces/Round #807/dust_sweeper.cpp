#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i < n; ++i){
    ans += a[i];
  }

  int k = 1;
  for( ; k < n && a[k] == 0; ++k);

  for( ; k < n; ++k){
    ans += (a[k] == 0);
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