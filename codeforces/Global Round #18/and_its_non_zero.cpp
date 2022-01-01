#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>

int GetCount(int k, int n){
  int p = (1 << (k + 1));

  int x = n / p;
  n %= p;

  return x * (p / 2) + max(0, n - p / 2 + 1);
}

int GetCount(int k, int l, int r){
  return GetCount(k, r) - GetCount(k, l - 1);
}
 
int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);

  int n = r - l + 1, ans = n - 1;
  for(int k = 0; (1 << k) <= r; ++k){
    ans = min(ans, n - GetCount(k, l, r));
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