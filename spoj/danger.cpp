#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, z;
  scanf("%de%d", &n, &z);

  while(z--){
    n *= 10;
  }

  if(n == 0){
    exit(0);
  }

  int m = 1;
  while(m <= n){
    m <<= 1;
  }
  m /= 2;

  return 2 * (n - m) + 1;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}