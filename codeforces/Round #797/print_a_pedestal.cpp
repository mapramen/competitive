#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  int m = (n - 6) / 3;
  n -= (6 + 3 * m);

  printf("%d %d %d\n", m + 2 + (n == 2), m + 3 + (n != 0), m + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}