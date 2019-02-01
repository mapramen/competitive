#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], b[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    b[i] = max(1 + a[i], b[i - 1]);
  }

  for(int i = n - 1; i > 0; --i)
    b[i] = max(b[i], b[i + 1] - 1);

  ll ans = 0;
  for(int i = 1; i <= n; ++i)
    ans += (b[i] - a[i] - 1);

  printf("%lld\n", ans);

  return 0;
}
