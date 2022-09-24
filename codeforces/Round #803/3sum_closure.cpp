#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N];
set<ll> S;

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);

  if(a[1] + a[2] + a[3] < a[1] || a[n - 2] + a[n - 1] + a[n] > a[n]){
    return false;
  }

  int k = 1;
  for( ; k <= n && a[k] != 0; ++k);
  reverse(a + k, a + n + 1);

  for( ; k <= n && a[k] != 0; ++k);
  n = min(n, k + 2);

  S.clear();
  for(int i = 1; i <= n; ++i){
    S.insert(a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      for(int k = j + 1; k <= n; ++k){
        if(S.count(a[i] + a[j] + a[k]) == 0){
          return false;
        }
      }
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}