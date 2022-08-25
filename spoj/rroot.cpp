#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int s;
  scanf("%d", &s);
  return 1 - sqrt(2.0 / s) / 3;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.6lf\n", Solve());
  }
  return 0;
}