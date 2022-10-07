#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  int m = 1;
  for( ; m <= n; m *= 2);
  m /= 2;

  int r = (2 * (n % m)) % n;
  return r == 0 ? n : r;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}