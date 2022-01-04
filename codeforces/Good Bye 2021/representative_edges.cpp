#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 71

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = max(0, n - 2);
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int ansx = 0, x1 = j - i, y1 = a[j] - a[i];
      for(int k = 1; k <= n; ++k){
        if(k == i || k == j){
          continue;
        }
        int x2 = k - i, y2 = a[k] - a[i];
        ansx += (1ll * x2 * y1 != 1ll * x1 * y2);
      }
      ans = min(ans, ansx);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}