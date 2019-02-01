#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector<int> v[N];
int x[N], y[N], pos[N], order[N];
ll ans[N];

bool cmp(int i, int j){
  return x[i] + y[j] < x[j] + y[i];
}

int main(){
  int n, m;
  ll X = 0, Y = 0;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
    Y += y[i];
    order[i] = i;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    v[i].PB(j);
    v[j].PB(i);
  }

  sort(order + 1, order + n + 1, cmp);

  for(int i = 1; i <= n; ++i){
    pos[order[i]] = i;
  }

  for(int j = 1; j <= n; ++j){
    int i = order[j];
    Y -= y[i];
    ll ansx = X + Y + 1ll * (n - j) * x[i] + 1ll * (j - 1) * y[i];

    for(auto k : v[i]){
      if(pos[k] < pos[i]){
        ansx -= (x[k] + y[i]);
      }
      else{
        ansx -= (x[i] + y[k]);
      }
    }

    ans[i] = ansx;

    X += x[i];
  }

  for(int i = 1; i <= n; ++i){
    printf("%lld ", ans[i]);
  }
  printf("\n");

  return 0;
}
