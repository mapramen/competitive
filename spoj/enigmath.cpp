#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  int g = __gcd(a, b);

  printf("%d %d\n", b / g, a / g);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}