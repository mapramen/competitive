#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    int ans = 0;
    ll s = a[1];
    for(int i = 2; i <= n; ++ans){
      int j = min(i + s, 1ll * n + 1);
      for( ; i < j; ++i){
        s += a[i];
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
