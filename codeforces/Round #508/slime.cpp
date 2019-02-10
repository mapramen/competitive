#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

int a[N];

int main(){
  int n, pCount = 0, nCount = 0;
  ll s = 0, ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    s += abs(a[i]);
    pCount += (a[i] > 0);
    nCount += (a[i] < 0);
  }

  if(n == 1){
    printf("%d\n", a[1]);
    return 0;
  }

  if(pCount != n && nCount != n){
    printf("%lld\n", s);
    return 0;
  }

  for(int i = 1; i < n; ++i){
    s -= (abs(a[i]) + abs(a[i + 1]));
    ans = max(ans, abs(a[i] - a[i + 1]) + s);
    s += (abs(a[i]) + abs(a[i + 1]));
  }

  printf("%lld\n", ans);

  return 0;
}
