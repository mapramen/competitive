#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
map<ll,int> C;

ll Solve(){
  int n;
  scanf("%d", &n);

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  s *= 2;
  if(s % n != 0){
    return 0ll;
  }

  s /= n;
  C.clear();

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += C[s - a[i]];
    ++C[a[i]];
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