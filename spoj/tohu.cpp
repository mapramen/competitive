#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int n;
  scanf("%d", &n);

  double ans = 0.5;
  ans /= (n + 1);
  ans /= (n + 2);
  ans = 0.75 - ans;

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.11lf\n", Solve());
  }
  return 0;
}