#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int q, p;
  scanf("%d%d", &q, &p);
  
  if(q == 0 && p == 0){
    exit(0);
  }

  return 1.0 * max(0, p + 1 - q) / (p + 1);
}

int main(){
  while(true){
    printf("%lf\n", Solve());
  }
  return 0;
}