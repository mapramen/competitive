#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  double a, b, c, d;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

  double s = (a + b + c + d) / 2;
  return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.2f\n", Solve());
  }
  return 0;
}