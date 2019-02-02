#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

vector< vector<int> > adj(N);
int a[N], subtreeSize[N], minB[N], maxB[N], dp1[N][N], dp2[N][N];

void DFS(int i, int p = 0){
  subtreeSize[i] = 1;
  dp1[i][1] = a[i];
  dp2[i][1] = a[i];

  for(auto k : adj[i]){
    if(k == p){
      continue;
    }

    DFS(k, i);

    for(int x = subtreeSize[i] + 1; x <= subtreeSize[k] + subtreeSize[i]; ++x){
      dp1[i][x] = INT_MAX;
      dp2[i][x] = 0;
    }

    for(int x = subtreeSize[i]; x > 0; --x){
      for(int y = 1, z = x + y; y <= subtreeSize[k]; ++y, ++z){
        dp1[i][z] = min(dp1[i][z], dp1[i][x] + dp1[k][y]);
        dp2[i][z] = max(dp2[i][z], dp2[i][x] + dp2[k][y]);
      }
    }

    subtreeSize[i] += subtreeSize[k];
  }
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, q;

    scanf("%d%d", &n, &q);
    for(int x = 1; x < n; ++x){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    DFS(1);

    for(int i = 1; i <= n; ++i){
      minB[i] = INT_MAX;
      maxB[i] = 0;
    }

    for(int i = 1; i <= n; ++i){
      for(int j = 0; j <= subtreeSize[i]; ++j){
        minB[j] = min(minB[j], dp1[i][j]);
        maxB[j] = max(maxB[j], dp2[i][j]);
      }
      adj[i].clear();
    }

    while(q--){
      int s, b;
      scanf("%d%d", &s, &b);
      if(minB[s] <= b && b <= maxB[s]){
        printf("Yes\n");
      }
      else{
        printf("No\n");
      }
    }
  }

  return 0;
}
