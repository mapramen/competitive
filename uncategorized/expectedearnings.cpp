#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 1000000

int main(){
  ll n, X, S = 0;
  double ans = 0;

  scanf("%lld%lld", &n, &X);
  for(int i = 0; i <= n; ++i){
    ll a;
    scanf("%lld", &a);
    S += i * a;
  }

  S -= n * X;

  if(S > 0){
    ans = S;
    ans /= M;
  }

  printf("%.15lf\n", ans);

  return 0;
}
