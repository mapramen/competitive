#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N], c[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  c[n] = 1;
  for(int i = n - 1; i != 0; --i){
    c[i] = a[i] != a[i + 1] ? 1 : 1 + c[i + 1];
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int ansx = c[i] - 1;
    i += (c[i] - 1);

    int j = i;
    while(j <= n){
      ++ansx;
      j = lower_bound(a + j + c[j], a + n + 1, 2 * a[j] - a[i]) - a;
    }
    ans = max(ans, ansx);
  }

  return n - ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}