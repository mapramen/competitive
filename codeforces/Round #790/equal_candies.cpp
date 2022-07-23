#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int s = 0, m = INT_MAX;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s += x, m = min(m, x);
  }

  return s - n * m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}