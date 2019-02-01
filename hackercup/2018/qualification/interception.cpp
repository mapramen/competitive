#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Solve(){
  int n;

  scanf("%d", &n);
  for(int i = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
  }

  n %= 2;
  printf("%d\n", n);

  if(n){
    printf("0.0\n");
  }
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
