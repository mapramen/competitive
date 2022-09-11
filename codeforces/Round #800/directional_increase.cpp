#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  if(a[n] != 0){
    return false;
  }

  int k = 1;
  for( ; k <= n && a[k] > 0; ++k);
  for( ; k <= n && a[k] == 0; ++k);
  return k > n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}