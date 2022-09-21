#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int degree[N], parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    degree[i] = 0, parent[i] = i;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    degree[i] += k, degree[j] += k;
    Union(i, j);
  }

  for(int i = 1; i <= n; ++i){
    if(Find(i) != 1){
      return 0;
    }
  }

  int odd_degree_cnt = 0;
  for(int i = 1; i <= n; ++i){
    odd_degree_cnt += (degree[i] % 2 == 1);
  }

  if(odd_degree_cnt > 2){
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    if(degree[i] % 2 == 1){
      return i;
    }
  }

  return 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int i = Solve();

    if(i == 0){
      printf("NO\n");
    }
    else{
      printf("YES %d\n", i);
    }
  }
  return 0;
}