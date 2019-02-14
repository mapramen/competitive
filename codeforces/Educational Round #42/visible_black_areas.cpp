#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 15010

bitset<N> v[N], mask;
int X1, X2, Y1, Y2, x[N], y[N];

int Compress(int n, int x[], int& x1, int& x2){
  vector<int> v;
  for(int i = 0; i < n; ++i)
    v.PB(x[i]);
  v.PB(x1);
  v.PB(x2);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 0; i < n; ++i)
    x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();

  x1 = lower_bound(v.begin(), v.end(), x1) - v.begin();
  x2 = lower_bound(v.begin(), v.end(), x2) - v.begin();

  if(x1 > x2)
    swap(x1, x2);

  return v.size();
}

void DFS(int x, int y){
  v[y].reset(x);

  if(x < N && v[y].test(x + 1)){
    DFS(x + 1, y);
  }

  if(y < N && v[y + 1].test(x)){
    DFS(x, y + 1);
  }

  if(x > 0 && v[y].test(x - 1)){
    DFS(x - 1, y);
  }

  if(y > 0 && v[y - 1].test(x)){
    DFS(x, y - 1);
  }
}

int main(){
  int n;

  scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);

  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d%d", &x[i], &y[i]);

  int mx = Compress(n, x, X1, X2);
  int my = Compress(n, y, Y1, Y2);

  for(int i = 0; i < n; ++i){
    int j = (i + 1) % n;
    if(y[i] == y[j]){
      v[y[i]].set(x[i]);
      v[y[j]].set(x[j]);
    }
  }

  for(int j = 0; j < my; ++j){
    bool k = v[j][0];
    for(int i = 1; i < mx; ++i){
      k ^= v[j][i];
      v[j][i] = k;
    }

    if(j)
      v[j] ^= v[j - 1];
  }

  for(int i = X1; i < X2; ++i)
    mask.set(i);

  for(int j = 0; j < my; ++j){
    if(j < Y1 || j >= Y2)
      v[j].reset();
    else
      v[j] &= mask;
  }

  int ans = 0;
  for(int j = Y1; j < Y2; ++j){
    if(!v[j].any()){
      continue;
    }

    for(int i = X1; i < X2; ++i){
      if(!v[j].test(i)){
        continue;
      }
      ++ans;
      DFS(i, j);
    }
  }

  printf("%d\n", ans);

  return 0;
}
