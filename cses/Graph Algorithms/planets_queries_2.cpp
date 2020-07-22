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

vector<vector<int>> adj(N);
int parent[N], pos[N], d[N], loopStart[N], loopLength[N], root[N], startTime[N], endTime[N], timer;
bool visited[N], calculated[N], isInLoop[N];

void DFS(int i, int r, int ls, int ll){
  startTime[i] = ++timer;
  root[i] = r;
  loopStart[i] = ls;
  loopLength[i] = ll;
  for(int j: adj[i]){
    if(isInLoop[j]){
      continue;
    }
    DFS(j, r, ls, ll);
  }
  endTime[i] = timer;
}

bool IsAncestor(int i, int j){
  return startTime[i] <= startTime[j] && endTime[j] <= endTime[i];
}

int Query(int i, int j){
  if(IsAncestor(j, i)){
    return d[i] - d[j];
  }

  if(root[i] == root[j] || loopStart[i] != loopStart[j] || !isInLoop[j]){
    return -1;
  }

  int x = d[i] - d[root[i]], y = (loopLength[i] + d[root[i]] - d[j]) % loopLength[i];

  return x + y;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int j = 1; j <= n; ++j){
    int i;
    scanf("%d", &i);
    parent[j] = i;
    adj[i].push_back(j);
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }

    int j = i;
    vector<int> v;

    for( ; !visited[j]; j = parent[j]){
      visited[j] = true;
      pos[j] = v.size();
      v.push_back(j);
    }

    if(!calculated[j]){
      int lStart = j, lLength = v.size() - pos[j];
      for(int x = pos[j]; x < v.size(); ++x){
        int k = v[x];
        isInLoop[k] = true;
        loopStart[k] = lStart;
        loopLength[k] = lLength;
      }
    }

    reverse(v.begin(), v.end());

    for(int k: v){
      d[k] = 1 + d[parent[k]];
      calculated[k] = true;
    }
  }

  for(int i = 1; i <= n; ++i){
    if(!isInLoop[i]){
      continue;
    }
    DFS(i, i, loopStart[i], loopLength[i]);
  }

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", Query(i, j));
  }

  return 0;
}