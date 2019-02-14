#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > v;
int a[N], p[N];

int main(){
  int n, t, k, i, j, kmin, kmax, x, y;

  scanf("%d%d%d", &n, &t, &k);

  for(i = 1; i <= t; i++)
    scanf("%d", &a[i]);

  for(i = 1, kmin = kmax = a[t]; i < t; i++){
    kmin += max(0, a[i] - a[i + 1]);
    kmax += (a[i] - 1);
  }

  if(k < kmin || k > kmax){
    printf("-1\n");
    return 0;
  }

  v.resize(t + 1);
  v[0].PB(1);

  for(i = 2, j = 1; j <= t; j++)
    for(int x = 0; x < a[j]; x++, i++)
      v[j].PB(i);

  for(i = 0; i < v[1].size(); i++)
    p[v[1][i]] = 1;

  for(i = 1; i < t; i++){
    for(j = 0; j < v[i + 1].size(); j++)
      p[v[i + 1][j]] = v[i][0];

    x = 1, y = 1;
    while(k < kmax && x < v[i].size() && y < v[i + 1].size()){
      p[v[i + 1][y]] = v[i][x];
      x++, y++, k++;
    }
  }

  printf("%d\n", n);

  for(i = 1; i <= n; i++)
    if(p[i] != 0)
      printf("%d %d\n", p[i], i);

  return 0;
}
