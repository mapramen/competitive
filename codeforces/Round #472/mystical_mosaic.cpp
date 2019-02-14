#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

char s[N][N], t[N][N];
ll a[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 0; i < n; ++i){
    ll mask = 0;
    for(int j = 0; j < m; ++j)
      if(s[i][j] == '#')
        mask |= (1ll << j);
    a[i] = mask;
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      t[i][j] = '.';

  for(ll i = 0, mask = (1ll << m) - 1; i < n; ++i){
    vector<ll> rows, columns;
    rows.PB(i);

    for(ll j = i + 1; j < n; ++j)
      if(a[j] == a[i]){
        rows.PB(j);
        a[j] = 0;
      }

    a[i] &= mask;
    for(ll j = 0; j < m; ++j){
      if((a[i] & (1ll << j)) > 0)
        columns.PB(j);
    }

    for(auto x : rows)
      for(auto y : columns)
        t[x][y] = '#';

    mask &= (((1ll << m) - 1) ^ a[i]);
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
      if(s[i][j] != t[i][j]){
        printf("No\n");
        return 0;
      }
    }

  printf("Yes\n");

  return 0;
}
