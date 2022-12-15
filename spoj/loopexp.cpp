#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int n;
  scanf("%d", &n);

  double ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += 1.0 / i;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lf\n", Solve());
  }
  return 0;
}