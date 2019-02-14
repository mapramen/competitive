#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define B 10

int offmin[B][N], onmin[B][N], ans[N];

int main(){
  int n, i, j, k;

  scanf("%d", &n);

  for(i = 0; (1 << i) <= n; i++){
    vector<int> v;

    for(j = 1; j <= n; j++)
      if((j & (1 << i)))
        v.PB(j);

    printf("%d\n", (int)v.size());

    for(k = 0; k < v.size(); k++)
      printf("%d ", v[k]);
    printf("\n");

    fflush(stdout);

    for(j = 1; j <= n; j++)
      scanf("%d", &onmin[i][j]);
  }

  for(i = 0; (1 << i) <= n; i++){
    vector<int> v;

    for(j = 1; j <= n; j++)
      if((j & (1 << i)) == 0)
        v.PB(j);

    printf("%d\n", (int)v.size());

    for(k = 0; k < v.size(); k++)
      printf("%d ", v[k]);
    printf("\n");

    fflush(stdout);

    for(j = 1; j <= n; j++)
      scanf("%d", &offmin[i][j]);
  }

  for(i = 1; i <= n; i++){
    ans[i] = INT_MAX;
    for(j = 0; (1 << j) <= n; j++){
      if((i & (1 << j)) == 0)
        ans[i] = min(ans[i], onmin[j][i]);
      else
        ans[i] = min(ans[i], offmin[j][i]);
    }
  }

  printf("-1\n");
  for(i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  fflush(stdout);

  return 0;
}
