#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000000007

int a[N], c[N];
set<int> S;

int main(){
  int n, p;
  scanf("%d%d", &n, &p);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  c[0] = 1, c[1] = 1;
  for(int i = 2; i < N; ++i){
    c[i] = (c[i - 1] + c[i - 2]) % MOD;
  }

  for(int i = 1; i < N; ++i){
    c[i] = (c[i] + c[i - 1]) % MOD;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x = a[i], y = a[i];
    bool should_skip = false;

    while(!should_skip && y > 0){
      if(S.count(y) != 0){
        should_skip = true;
        continue;
      }

      if(y % 4 == 0){
        y /= 4;
      }
      else if(y % 2 == 1){
        y = (y - 1) / 2;
      }
      else{
        break;
      }
    }

    if(should_skip){
      continue;
    }
    
    S.insert(x);

    int m = 32 - __builtin_clz(x);
    if(m > p){
      continue;
    }

    ans = (ans + c[p - m]) % MOD;
  }

  printf("%d\n", ans);
  
  return 0;
}