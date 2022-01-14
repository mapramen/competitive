#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Print(int n, int m, int x){
  int p = n / m, r = n % m;
  for(int i = 1; i <= m; ++i){
    int c = p + (i <= r);
    
    printf("%d ", c);
    while(c--){
      printf("%d ", x + 1);
      x = (x + 1) % n;
    }
    printf("\n");
  }
}

void Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int p = (n + m - 1) / m, r = n % m, x = 0;
  while(k--){
    Print(n, m, x);
    x = (x + r * p) % n;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}