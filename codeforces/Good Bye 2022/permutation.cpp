#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int l = 1, r = n, i = 1; l <= r; ){
    for(int x = 1; x < k && i <= n; ++x, ++i){
      printf("%d ", r--);
    }

    if(i <= n){
      printf("%d ", l++);
      ++i;
    }
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}