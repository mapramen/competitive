#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000000

vector<int> c;
int parent[N], v[N], e[N];
pii a[N], b[N];

int Find(int i){
  return (i == parent[i]) ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i != j){
    if(i > j){
      swap(i, j);
    }
    parent[j] = i;
    v[i] += v[j];
    e[i] += e[j];
    b[i] = max(max(b[i], b[j]), MP(max(b[i].first, b[j].first), min(b[i].first, b[j].first)));
  }
  ++e[i];
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    c.PB(i);
    c.PB(j);
    a[x] = MP(i, j);
  }

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for(int x = 0; x < n; ++x){
    int i, j;
    tie(i, j) = a[x];
    i = lower_bound(c.begin(), c.end(), i) - c.begin();
    j = lower_bound(c.begin(), c.end(), j) - c.begin();
    a[x] = MP(i, j);
  }

  for(int i = 0; i < c.size(); ++i){
    parent[i] = i;
    v[i] = 1;
    e[i] = 0;
    b[i] = MP(c[i], 0);
  }

  for(int x = 0; x < n; ++x){
    int i, j;
    tie(i, j) = a[x];
    Union(i, j);
  }

  int ans = 0;
  for(int i = 0; i < c.size() && ans >= 0; ++i){
    if(parent[i] != i){
      continue;
    }
    if(e[i] > v[i]){
      ans = -1;
    }
    else{
      ans = max(ans, e[i] == v[i] ? b[i].first : b[i].second);
    }
  }

  printf("%d\n", ans);

  return 0;
}
