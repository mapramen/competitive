#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int parent[N], sz[N], max_size = 0;
priority_queue<pii,vector<pii>,greater<pii>> Q;

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void SetSize(int i, int szi){
  sz[i] = szi;
  max_size = max(max_size, szi);
  Q.push({szi, i});
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  SetSize(i, sz[i] + sz[j]);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
    SetSize(i, 1);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);

    while(sz[Find(Q.top().second)] != Q.top().first){
      Q.pop();
    }

    printf("%d\n", max_size - Q.top().first);
  }

  return 0;
}