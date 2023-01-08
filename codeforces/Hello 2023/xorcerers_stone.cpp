#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define M 32

vector<vector<int>> adj(N);
int a[N], sz[N], child_pointer[N][M];
pii sibling_pointer[N][M];
vector<int> ans;

void DFS(int i){
  sz[i] = 1;

  for(int j: adj[i]){
    DFS(j);

    a[i] ^= a[j];
    sz[i] += sz[j];

    for(int x = 0; x < M; ++x){
      for(int y = 0; y < M; ++y){
        if(child_pointer[i][x] == 0 || child_pointer[j][y] == 0){
          continue;
        }
        sibling_pointer[j][(x ^ y)] = {child_pointer[i][x], x};
      }
    }

    for(int y = 0; y < M; ++y){
      if(child_pointer[j][y] == 0 && sibling_pointer[j][y].first == 0){
        continue;
      }
      child_pointer[i][y] = j;
    }
  }

  if(sz[i] % 2 == 0){
    child_pointer[i][a[i]] = i;
  }
}

void CollectAns(int i, int x){
  if(child_pointer[i][x] == i){
    ans.push_back(i);
    return;
  }

  i = child_pointer[i][x];
  while(x != 0){
    auto [j, y] = sibling_pointer[i][x];
    CollectAns(i, x ^ y);
    i = j, x = y;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  DFS(1);

  if(a[1] == 0){
    printf("1\n1\n");
    return 0;
  }

  if(child_pointer[1][a[1]] == 0){
    printf("-1\n");
    return 0;
  }

  CollectAns(1, a[1]);
  ans.push_back(1);

  printf("%lu\n", ans.size());
  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}