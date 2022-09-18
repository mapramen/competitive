#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int l = 1;
  for( ; l <= n && a[l] == 0; ++l);

  int r = n;
  for( ; r > 0 && a[r] == 0; --r);

  if(r < l){
    return 0;
  }

  for(int i = l; i <= r; ++i){
    if(a[i] == 0){
      return 2;
    }
  }

  return 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}