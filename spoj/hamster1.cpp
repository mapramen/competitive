#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int v, k1, k2;
  scanf("%d%d%d", &v, &k1, &k2);

  double angle = atan2(4 * k1, -k2) / 2;
  double ans = v * v * (sqrt(16 * k1 * k1 + k2 * k2) + k2) / (4 * 10);
  printf("%.3lf %.3lf\n", angle, ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}