#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

int main(){
  int n, k;
  double ans = 0;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(ll i = 1, sx = 0; i <= n; i++){
    sx += a[i];
    if(i >= k){
      sx -= a[i - k];
      ans += sx;
    }
  }

  ans /= (n - k + 1);

  printf("%.15lf\n", ans);

  return 0;
}
