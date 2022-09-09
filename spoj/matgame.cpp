#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

int a[N];

int Update(int x, int y){
  return x > y ? x : max(0, x - 1);
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int g = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[j]);
    }

    int gx = 0;
    for(int j = m; j != 0; --j){
      gx = Update(a[j], gx);
    }
    g ^= gx;
  }

  return g != 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "FIRST" : "SECOND");
  }
  return 0;
}