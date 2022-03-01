#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  return c % __gcd(a, b) == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %s\n", k, Solve() ? "Yes" : "No");
  }
  return 0;
}