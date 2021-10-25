#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  return 2 * (n - k) + 2 * ((k - 1) / 2);
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}