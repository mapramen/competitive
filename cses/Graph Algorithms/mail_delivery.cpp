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
#define N 100001
#define M 200001

vector<vector<int>> edgeNos(N);
int edgeXors[M], nextIndex[N];
bool edgeVisited[M];
vector<int> ans;

void DFS(int i){
  for( ; nextIndex[i] < edgeNos[i].size(); ++nextIndex[i]){
    int edgeNo = edgeNos[i][nextIndex[i]];
    if(edgeVisited[edgeNo]){
      continue;
    }
    edgeVisited[edgeNo] = true;
    DFS(i ^ edgeXors[edgeNo]);
  }
  ans.push_back(i);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    edgeNos[i].push_back(x);
    edgeNos[j].push_back(x);
    edgeXors[x] = i ^ j;
  }

  for(int i = 1; i <= n; ++i){
    if(edgeNos[i].size() % 2 == 1){
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  DFS(1);

  if(ans.size() != m + 1){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  for(int x: ans){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}