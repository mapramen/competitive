#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N], inf = INT_MAX;

int main(){
  int n, m, k, ans = inf;

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  for(int j = 1; j <= n; j++)
    if(a[j] != 0 && a[j] <= k)
      ans = min(ans, 10 * abs(m - j));

  printf("%d\n", ans);

  return 0;
}
