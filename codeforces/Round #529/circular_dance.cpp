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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
vector<int> ans;
bool visited[N];
map< pii, int > M;

void AddEdge(int i, int j){
  ++M[make_pair(i, j)];
}

void DFS(int i){
  ans.push_back(i);
  visited[i] = true;
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
}

int main(){
  int n;
  
  scanf("%d", &n);

  for(int x = 1; x <= n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    AddEdge(x, i);
    AddEdge(x, j);
    AddEdge(i, j);
    AddEdge(j, i);
  }

  for(auto q : M){
    if(q.second != 2){
      continue;
    }
    int i, j;
    tie(i, j) = q.first;
    adj[i].push_back(j);
  }

  DFS(1);

  for(int i : ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}