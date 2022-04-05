#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];
int parent[N * N];

int Find(int i){
  return parent[i] == i ? parent[i] : parent[i] = Find(parent[i]);
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

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int i = 0; i < n * m; ++i){
    parent[i] = i;
  }

  for(int x = 0; x < n; ++x){
    for(int y = 1; y < m; ++y){
      if(s[x][y - 1] == 'E' || s[x][y] == 'W'){
        Union(x * m + y - 1, x * m + y);
      }
    }
  }

  for(int y = 0; y < m; ++y){
    for(int x = 1; x < n; ++x){
      if(s[x - 1][y] == 'S' || s[x][y] == 'N'){
        Union((x - 1) * m + y, x * m + y);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n * m; ++i){
    ans += (parent[i] == i);
  }

  printf("%d\n", ans);
  
  return 0;
}