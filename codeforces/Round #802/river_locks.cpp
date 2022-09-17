#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N], b[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);    
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
    b[i] = max(b[i - 1], (a[i] + i - 1) / i);
  }

  for(int i = n; i != 0; --i){
    b[i] = max(b[i - 1], (a[n] + i - 1) / i);
  }

  for(int i = 1, j = n; i < j; ++i, --j){
    swap(b[i], b[j]);
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int t;
    scanf("%d", &t);
    int x = upper_bound(b + 1, b + n + 1, 1ll * t) - b - 1;
    x = n - x + 1;
    if(x > n){
      x = -1;
    }
    printf("%d\n", x);
  }

  return 0;
}