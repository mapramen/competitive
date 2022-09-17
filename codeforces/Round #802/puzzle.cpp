#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[2][N];

void ReadPuzzle(int n, int mul){
  for(int x = 0; x < 2; ++x){
    for(int i = 1; i <= n; ++i){
      int z;
      scanf("%d", &z);
      a[x][i] += mul * z;
    }
  }
}

bool IsSolvable(int n){
  int ans = 0;
  for(int x = 0; x < 2; ++x){
    for(int i = 1; i <= n; ++i){
      ans += a[x][i];
    }
  }
  return ans == 0;
}

int main(){
  int n;
  scanf("%d", &n);

  ReadPuzzle(n, 1);
  ReadPuzzle(n, -1);

  if(!IsSolvable(n)){
    printf("-1\n");
    return 0;
  }

  ll ans = 0;
  for(int i = 1, s1 = 0, s2 = 0; i <= n; ++i){
    s1 += a[0][i], s2 += a[1][i];
    if(min(s1, s2) < 0 && max(s1, s2) > 0){
      int z = min(abs(s1), abs(s2));
      
      if(s1 < 0){
        s1 += z, s2 -= z;
      }
      else{
        s1 -= z, s2 += z;
      }
      
      ans += z;
    }
    ans += abs(s1) + abs(s2);
  }

  printf("%lld\n", ans);
  
  return 0;
}