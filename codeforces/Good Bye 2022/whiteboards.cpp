#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N];

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int x;
    scanf("%d", &x);

    sort(a + 1, a + n + 1);
    a[1] = x;
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += a[i];
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