#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

ll nCr(int n, int r){
  if(n < 0 || r < 0 || r > n)
    return 0ll;
  else if(r == 0)
    return 1ll;
  else{
    ll ans = 1;

    for(int i = 0; i < r; i++)
      ans *= (n - i);

    for(int i = 1; i <= r; i++)
      ans /= i;

    return ans;
  }
}

int main(){
  int n;
  ll ans = 1;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  sort(a + 1, a + n + 1);

  for(int i = 1; i <= 3; i++){
    if(a[i] == a[i - 1])
      continue;

    int m = 0, r = 0;
    for(int j = i; j <= 3; j++)
      r += (a[j] == a[i]);

    for(int j = 1; j <= n; j++)
      m += (a[j] == a[i]);

    ans *= nCr(m, r);
  }

  printf("%lld\n", ans);

  return 0;
}
