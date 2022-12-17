#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

bool IsDifferentThanPrevious(int n, int i){
  if(i <= 1 || i > n){
    return false;
  }
  return a[i] != a[i - 1];
}

ll GetContribution(int n, int i){
  return 1ll * (i - 1) * (n - i + 1) * IsDifferentThanPrevious(n, i);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 1ll * n * (n + 1) / 2;
  for(int i = 1; i <= n; ++i){
    ans += GetContribution(n, i);
  }

  while(m--){
    int i, x;
    scanf("%d%d", &i, &x);

    ans -= (GetContribution(n, i) + GetContribution(n, i + 1));

    a[i] = x;
    ans += (GetContribution(n, i) + GetContribution(n, i + 1));

    printf("%lld\n", ans);
  }
  
  return 0;
}