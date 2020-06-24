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

vector<vector<int>> adj(N), rAdj(N);
vector<int> topologicalOrder;
int assigned[N];
bool visited[N];

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topologicalOrder.push_back(i);
}

void AssignDFS(int i, int x){
  if(assigned[i]){
    return;
  }

  assigned[i] = x;
  for(int j: rAdj[i]){
    AssignDFS(j, x);
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    rAdj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topologicalOrder.begin(), topologicalOrder.end());

  int ans = 0;
  for(int i: topologicalOrder){
    AssignDFS(i, ++ans);
    ans -= (assigned[i] != ans);
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", assigned[i]);
  }
  printf("\n");

  return 0;
}