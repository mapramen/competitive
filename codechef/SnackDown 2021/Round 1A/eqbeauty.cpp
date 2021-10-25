#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

ll Calculate1(int n){
  return n < 4 ? LLONG_MAX : (a[n] - a[n - 1] + a[2] - a[1]);
}

ll Calculate2(int n){
  if(n < 4){
    return LLONG_MAX;
  }

  int ans = INT_MAX;
  for(int i = 3; i < n; ++i){
    int ansx = abs((a[i - 1] - a[1]) - (a[n] - a[i]));
    ans = min(ans, ansx);
  }

  return ans;
}

ll Calculate3(int n){
  if(n < 4){
    return LLONG_MAX;
  }

  int ans = INT_MAX;

  for(int i = n - 2, j = n; i > 1; --i){
    int d = a[n] - a[i];

    for(j = max(j, i + 1); j != n && a[j] - a[1] <= d; ++j);

    if(j != i + 1){
      --j;
    }

    for(int k = 0; k < 3 && j != n; ++k, ++j){
      int ansx = abs((a[j] - a[1]) - d);
      ans = min(ans, ansx);
    }

    j = j - 4;
  }

  return ans;
}

ll Calculate4(int n){
  int m = n / 2;

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i];
  }

  ll p = 0;
  for(int i = 1; i <= m + 1; ++i){
    p += a[i];
  }

  int x = *min_element(a + 1, a + m + 1);
  ll ans1 = (1ll * m * a[m + 1] - (p - x)) + ((s - p) - 1ll * (n - (m + 1)) * a[m + 1]);;

  p -= a[m + 1];
  int y = *max_element(a + m + 1, a + n + 1);
  ll ans2 = (1ll * m * a[m] - p) + ((s - p - y) - 1ll * (n - 1 - m) * a[m]);

  return min(ans1, ans2);
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  if(n == 2){
    return 0;
  }

  return min(min(Calculate1(n), Calculate2(n)), min(Calculate3(n), Calculate4(n)));
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}