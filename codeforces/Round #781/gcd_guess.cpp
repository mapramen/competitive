#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Query(int a, int b){
  printf("? %d %d\n", a, b);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

void Print(int ans){
  printf("! %d\n", ans);
  fflush(stdout);
}

void Solve(){
  int ans = 0, x = 0;
  
  for(int k = 0; k < 30; ++k){
    int p = (1 << k);
    if(Query(p + x, 3 * p + x) != p){
      ans += p;
      x -= p;
    }
  }

  Print(ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}