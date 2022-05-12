#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  n /= 2, --k;

  while(n != 0){
    int i = __builtin_ctz(n);
    n ^= (1 << i);

    int j = min(i, k - __builtin_popcount(n));
    if(j < 0){
      continue;
    }

    return 2 * (n ^ (((1 << j) - 1) << (i - j))) + 1;
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}