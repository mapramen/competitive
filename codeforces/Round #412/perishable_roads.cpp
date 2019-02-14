#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

int a[N][N];
ll d[N], inf = 1E18;
bool visited[N];

int main(){
  int n, min_weight = INT_MAX;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      scanf("%d", &a[i][j]);
      a[j][i] = a[i][j];
      min_weight = min(min_weight, a[i][j]);
    }
  }

  for(int i = 1; i <= n; i++){
    d[i] = inf;
    for(int j = 1; j <= n; j++){
      if(i == j)
        continue;
      a[i][j] -= min_weight;
      d[i] = min(d[i], 2ll * a[i][j]);
    }
  }

  d[0] = inf;
  for(int x = 1; x < n; x++){
    int i = 0;
    for(int j = 1; j <= n; j++){
      if(visited[j] == 0 && d[j] < d[i])
        i = j;
    }
    visited[i] = 1;
    for(int j = 1; j <= n; j++)
      d[j] = min(d[j], d[i] + a[i][j]);
  }

  for(int i = 1; i <= n; i++)
    printf("%lld\n", d[i] + 1ll * (n - 1) * min_weight);

  return 0;
}
