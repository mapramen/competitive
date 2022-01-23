#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, l;
  scanf("%d%d", &n, &l);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int ans = 0;
  for(int k = 0; k < l; ++k){
    int c = 0;
    for(int x: a){
      c += ((x & (1 << k)) != 0);
    }
    if(2 * c > n){
      ans += (1 << k);
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