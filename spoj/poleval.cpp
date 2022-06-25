#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(int t){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  vector<int> c(n + 1);
  for(int i = n; i != -1; --i){
    scanf("%d", &c[i]);
  }

  int k;
  scanf("%d", &k);

  printf("Case %d:\n", t);
  while(k--){
    int x;
    scanf("%d", &x);

    ll ans = 0;
    for(int i = n; i != -1; --i){
      ans = x * ans + c[i];
    }

    printf("%lld\n", ans);
  }
}

int main(){
  for(int k = 1; ; ++k){
    Solve(k);
  }
  return 0;
}