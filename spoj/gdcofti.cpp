#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  ull g = 0;
  for(int i = 1; i <= 3; ++i){
    ull x;
    scanf("%llu", &x);
    if(x == 0 && g == 0){
      continue;
    }
    g = __gcd(g, x);
  }
  printf("%llu\n", g);
  return 0;
}