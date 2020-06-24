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

vector<vector<int>> adj(N), rAdj(N);
vector<int> topologicalOrder;
int assigned[N];
bool visited[N];
char ch[2];

int ReadTopping(){
  int x;
  scanf("%s%d", ch, &x);
  return 2 * (x - 1) + (ch[0] == '-');
}

void AddEdge(int i, int j){
  adj[i].push_back(j);
  rAdj[j].push_back(i);
}

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

  scanf("%d%d", &m, &n);

  while(m--){
    int i = ReadTopping(), j = ReadTopping();
    AddEdge(i ^ 1, j);
    AddEdge(j ^ 1, i);
  }

  for(int i = 0; i < 2 * n; ++i){
    VisitDFS(i);
  }
  reverse(topologicalOrder.begin(), topologicalOrder.end());

  m = 0;
  for(int i: topologicalOrder){
    AssignDFS(i, ++m);
    m -= (assigned[i] != m);
  }

  vector<char> ans;

  for(int i = 0, j = 1; i < 2 * n; i += 2, j += 2){
    if(assigned[i] == assigned[j]){
      printf("IMPOSSIBLE\n");
      return 0;
    }

    ans.push_back(assigned[i] > assigned[j] ? '+' : '-');
  }

  for(char c: ans){
    printf("%c ", c);
  }
  printf("\n");

  return 0;
}