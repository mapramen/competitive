#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double sqrt3 = sqrt(3);

double Solve(){
  double v;
  scanf("%lf", &v);
  return cbrt(2 * 81 * sqrt(3) * v * v);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.10lf\n", Solve());
  }
  return 0;
}