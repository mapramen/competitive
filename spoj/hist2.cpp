#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 15
#define M (1 << N)

int a[N];
int cost[N][N], dp_perimeter[M][N], dp_count[M][N];

void Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cost[i][j] = 2 + 2 * max(0, a[j] - a[i]);
    }
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    for(int i = 0; i < n; ++i){
      dp_perimeter[mask][i] = 0, dp_count[mask][i] = 0;
    }
  }

  for(int i = 0; i < n; ++i){
    dp_perimeter[(1 << i)][i] = 2 + 2 * a[i];
    dp_count[(1 << i)][i] = 1;
  }

  for(int mask = 1; mask < (1 << n); ++mask){
    for(int imask = mask; imask != 0; ){
      int i = __builtin_ctz(imask);
      imask ^= (1 << i);

      for(int jmask = (1 << n) - 1 - mask; jmask != 0; ){
        int j = __builtin_ctz(jmask);
        jmask ^= (1 << j);

        int nmask = mask | (1 << j);
        int ans = dp_perimeter[mask][i] + cost[i][j], cnt = dp_count[mask][i];

        if(ans > dp_perimeter[nmask][j]){
          dp_perimeter[nmask][j] = ans, dp_count[nmask][j] = cnt;
        }
        else if(ans == dp_perimeter[nmask][j]){
          dp_count[nmask][j] += cnt;
        }
      }
    }
  }

  int ans = 0, cnt = 0;
  
  for(int mask = (1 << n) - 1, i = 0; i < n; ++i){
    if(dp_perimeter[mask][i] > ans){
      ans = dp_perimeter[mask][i], cnt = dp_count[mask][i];
    }
    else if(dp_perimeter[mask][i] == ans){
      cnt += dp_count[mask][i];
    }
  }

  printf("%d %d\n", ans, cnt);
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}