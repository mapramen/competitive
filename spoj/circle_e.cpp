#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3

double k[B];

double Solve(){
  for(int i = 0; i < B; ++i){
    int r;
    scanf("%d", &r);
    k[i] = 1.0 / r;
  }

  double ans = 0;
  for(int i = 0; i < B; ++i){
    ans += k[i] * k[(i + 1) % B];
  }

  ans = 2 * sqrt(ans);

  for(int i = 0; i < B; ++i){
    ans += k[i];
  }

  return 1 / ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lf\n", Solve());
  }
  return 0;
}