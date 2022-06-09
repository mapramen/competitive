#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int w, b;
  scanf("%d%d", &w, &b);
  return b % 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.6lf\n", Solve());
  }
  return 0;
}