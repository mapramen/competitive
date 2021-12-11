#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll SumOfN(int n){
  return 1ll * n * (n + 1) / 2;
}

ll GetCount(int n, int k){
  if(n <= k){
    return SumOfN(n);
  }

  return 2 * SumOfN(k - 1) + k - SumOfN(2 * k - 1 - n);
}

int Solve(){
  int k;
  ll m;
  scanf("%d%lld", &k, &m);

  int x = 1, y = 2 * k - 1, ans = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(GetCount(mid, k) >= m){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
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