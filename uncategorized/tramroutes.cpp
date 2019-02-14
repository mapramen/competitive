#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 10001
#define N 100001

vector< vector<int> > v(M);
int n, q, c[M], a[M], b[M], p[M], parent[N];
vector<int> ans, ansx;

void Reset(){
  for(int i = 1; i <= n; ++i)
    parent[i] = i;
}

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j)
    return 0;

  if(i > j)
    swap(i, j);
  parent[j] = i;
  return 1;
}

ll Check(int m){
  Reset();
  ll s = 0;
  ansx.clear();

  for(int t = 1; t <= m; ++t){
    int i = p[t];
    bool f = 0;
    for(int j = 1; j < v[i].size(); ++j){
      int x = v[i][j - 1], y = v[i][j];
      f |= Union(x, y);
    }
    if(f){
      s += c[i];
      ansx.PB(i);
    }
  }

  for(int i = 1; i <= q; ++i){
    if(Find(a[i]) != Find(b[i])){
      s = 2E18;
      break;
    }
  }

  return s;
}

void BinarySearch(int m){
  int x = 1, y = m;
  ll s = 0;
  for(int i = 1; i <= m; ++i){
    ans.PB(i);
    s += c[i];
  }
  while(x <= y){
    int mid = (x + y) / 2;
    if(Check(mid) < s){
      ans = ansx;
      y = mid - 1;
    }
    else
      x = mid + 1;
  }
}

bool cmp(int i, int j){
  return MP(c[i], -v[i].size()) <= MP(c[j], -v[j].size());
}

int main(){
  int m;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= m; ++i){
    scanf("%d", &c[i]);

    int k;
    scanf("%d", &k);
    while(k--){
      int j;
      scanf("%d", &j);
      v[i].PB(j);
    }
  }

  for(int i = 1; i <= q; ++i)
    scanf("%d%d", &a[i], &b[i]);

  for(int i = 1; i <= m; ++i)
    p[i] = i;

  sort(p + 1, p + m + 1, cmp);

  BinarySearch(m);

  printf("%lu\n", ans.size());
  for(auto x : ans)
    printf("%d ", x);
  printf("\n");

  return 0;
}
