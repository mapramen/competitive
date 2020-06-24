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
int edgeTo[M], nextIndex[N], outDegree[N];
vector<int> ans;

void DFS(int i){
  while(nextIndex[i] < edgeNos[i].size()){
    int j = edgeTo[edgeNos[i][nextIndex[i]]];
    ++nextIndex[i];
    DFS(j);
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
    edgeTo[x] = j;
    ++outDegree[i], --outDegree[j];
  }

  if(outDegree[1] != 1 || outDegree[n] != -1){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  for(int i = 2; i < n; ++i){
    if(outDegree[i] != 0){
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  DFS(1);
  reverse(ans.begin(), ans.end());

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