#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n % 2 == 1){
    return n;
  }

  int ans = 0;
  for( ; n > 0; n >>= 1){
    ans = (ans << 1) + (n % 2);
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