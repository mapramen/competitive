#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];
ll T1[N], T2[N];

void Update(ll T[], int i, int n, int x){
  for( ; i <= n; i += (i&-i))
    T[i] += x;
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

int main(){
  int n;
  ll ansC = 0, ansI = 0;
  double ans;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = n; i > 0; i--){
    ll c = Query(T1, a[i] - 1);
    ll d = Query(T2, a[i] - 1);
    ansC += (1ll * (n - i + 1) * i * (i - 1) - 4 * i * d);
    ansI += c;
    Update(T1, a[i], n, 1);
    Update(T2, a[i], n, n - i + 1);
  }

  ans = 2ll * n * (n + 1);
  ans = ansI + ansC / ans;

  printf("%.15lf\n", ans);

  return 0;
}
