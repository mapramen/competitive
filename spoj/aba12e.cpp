#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

ll a[N];

ll GetCount(int n, ll m){
  ll cnt = 0;
  for(int i = 1, j = 1; i <= n; ++i){
    for(j = max(j, i); j <= n && a[j] - a[i - 1] <= m; ++j);
    cnt += (j - i);
  }
  return cnt;
}

ll BinarySearch(int n, ll k){
  ll x = 0, y = 1E18, ans = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(GetCount(n, mid) >= k){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n;
  ll k;
  scanf("%d%lld", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  printf("%lld\n", BinarySearch(n, k));

  return 0;
}