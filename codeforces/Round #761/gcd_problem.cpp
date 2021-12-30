#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);
  
  int c = 1, a = 2, b = n - 3;
  while(__gcd(a, b) != 1){
    ++a, --b;
  }

  printf("%d %d %d\n", a, b, c);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}