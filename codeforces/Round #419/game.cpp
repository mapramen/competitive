#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int n, m, a[N][N], r[N], c[N];

int MinSteps(int k){
  int ans = 0;
  bool valid = 1;
  r[1] = k;

  for(int j = 1; j <= m && valid == 1; j++){
    c[j] = a[1][j] - r[1];
    valid = (c[j] >= 0);
  }

  for(int i = 1; i <= n && valid == 1; i++){
    r[i] = a[i][1] - c[1];
    valid = (r[i] >= 0);
  }

  for(int i = 1; i <= n && valid == 1; i++){
    for(int j = 1; j <= m && valid == 1; j++){
      valid = (r[i] + c[j] == a[i][j]);
    }
  }

  if(valid){
    for(int i = 1; i <= n; i++)
      ans += r[i];

    for(int j = 1; j <= m; j++)
      ans += c[j];
  }
  else
    ans = INT_MAX;

  return ans;
}

int main(){
  int ans = INT_MAX, k = INT_MAX;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      scanf("%d", &a[i][j]);

  for(int kx = 0; kx < 5 * N; kx++)
    tie(ans, k) = min(MP(ans, k), MP(MinSteps(kx), kx));

  ans = MinSteps(k);

  if(ans == INT_MAX)
    printf("-1\n");
  else{
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++){
      int x = r[i];
      while(x--)
        printf("row %d\n", i);
    }
    for(int j = 1; j <= m; j++){
      int x = c[j];
      while(x--)
        printf("col %d\n", j);
    }
  }

  return 0;
}
