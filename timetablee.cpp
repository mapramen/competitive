#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200002

ll a[N], b[N], c[N], inf = 4E18;
set<int> S;

int main(){
  int n;
  ll t;

  scanf("%d%lld", &n, &t);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 2; i <= n; ++i){
    S.insert(i);
  }

  a[n + 1] = inf;
  for(int i = 1; i <= n; ++i){
    b[i] = a[i] + t;
    c[i] = inf;
  }

  for(int i = 1; i <= n; ++i){
    int k;
    scanf("%d", &k);

    if(k < i){
      printf("No\n");
      return 0;
    }

    c[k] = min(c[k], a[k + 1] + t - 1);

    while(!S.empty()){
      auto it = S.upper_bound(i);

      if(it == S.end() || *it > k){
        break;
      }

      int j = *it;
      S.erase(j);

      b[j - 1] = max(b[j - 1], a[j] + t);
    }
  }

  for(int i = 1; i <= n; ++i){
    b[i] = max(b[i], 1 + c[i - 1]);
    c[i] = min(c[i], b[i]);
  }

  for(int i = 1; i <= n; ++i){
    if(c[i] < b[i]){
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  for(int i = 1; i <= n; ++i){
    printf("%lld ", b[i]);
  }
  printf("\n");

  return 0;
}
