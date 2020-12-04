#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N), val(N);
int d[N];

//----------------------------------- Centroid Decomposition -----------------------------------//
vector<vector<int>> centroidDistances(N);
int subtreeSize[N], centroidParent[N];
bool isCentroid[N];

int SubtreeSizeDFS(int i, int p){
  int ans = 1;
  
  for(int j: adj[i]){
    if(isCentroid[j] || j == p){
      continue;
    }
    ans += SubtreeSizeDFS(j, i);
  }

  subtreeSize[i] = ans;
  return ans;
}

int FindCentroidDFS(int i, int p, int s){
  for(int j: adj[i]){
    if(!isCentroid[j] && j != p && 2 * subtreeSize[j] > s){
      return FindCentroidDFS(j, i, s);
    }
  }
  return i;
}

int CentroidDistancesDFS(int c, int i, int p, int d){
  int ans = d;
  centroidDistances[i].push_back(d);

  for(int j: adj[i]){
    if(isCentroid[j] || j == p){
      continue;
    }
    ans = max(ans, CentroidDistancesDFS(c, j, i, d + 1));
  }

  return ans;
}

int CentroidDecompositionDFS(int i){
  SubtreeSizeDFS(i, 0);
  
  i = FindCentroidDFS(i, 0, subtreeSize[i]);
  isCentroid[i] = true;

  for(int j: adj[i]){
    if(isCentroid[j]){
      continue;
    }
    centroidParent[CentroidDecompositionDFS(j)] = i;
  }

  isCentroid[i] = false;
  int m = CentroidDistancesDFS(i, i, 0, 0);
  val[i].resize(m + 1);

  return i;
}
//--------------------------------- Centroid Decomposition Ends --------------------------------//

void InitialiseChipsDistance(int n){
  int k;
  scanf("%d", &k);

  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    d[i] = n;
  }

  while(k--){
    int i;
    scanf("%d", &i);
    Q.push(i);
    d[i] = 0;
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(d[j] != n){
        continue;
      }
      d[j] = 1 + d[i];
      Q.push(j);
    }
  }
}

void UpdateValue(vector<int> &v, int centroidDistance, int chipsDistance){
  int i = chipsDistance - centroidDistance - 1;
  if(i < 0){
    return;
  }
  i = min(i, (int)v.size() - 1);
  v[i] = max(v[i], chipsDistance);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  InitialiseChipsDistance(n);
  CentroidDecompositionDFS(1);

  for(int i = 1; i <= n; ++i){
    for(int c = i, k = 0; c != 0; c = centroidParent[c], ++k){
      UpdateValue(val[c], centroidDistances[i][k], d[i]);
    }
  }

  for(int c = 1; c <= n; ++c){
    vector<int> &v = val[c];
    int x = v.back();
    for(int k = ((int)v.size()) - 2; k > -1; --k){
      x = max(x, v[k]);
      v[k] = x;
    }
  }

  for(int i = 1; i <= n; ++i){
    int ans = 0;
    for(int c = i, k = 0; c != 0; c = centroidParent[c], ++k){
      ans = max(ans, val[c][centroidDistances[i][k]]);
    }
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}