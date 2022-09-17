#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  ll s = 0, ans = 0;
  for(int i = 2; i <= n; ++i){
    a[i] += s;
    if(a[i - 1] <= a[i]){
      s -= (a[i] - a[i - 1]);
      ans += a[i] - a[i - 1];
      a[i] = a[i - 1];
    }
    else{
      ans += a[i - 1] - a[i];
    }
  }

  ans += abs(a[n]);

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