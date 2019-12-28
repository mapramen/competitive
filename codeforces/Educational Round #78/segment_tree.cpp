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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 1000001

vector< vector<int> > adj(N);
int l[N], r[N], startVertex[N], endVertex[N];
bool visited[N];
map<int,int> M;

int DFS(int i){
  visited[i] = true;
  int ans = 1;
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    ans += DFS(j);
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &l[i], &r[i]);
    startVertex[l[i]] = i, endVertex[r[i]] = i;
  }
 
  int totalEdges = 0;
  for(int x = 1, m = 2 * n; x <= m && totalEdges < n; ++x){
    if(startVertex[x] == 0){
      continue;
    }

    int i = startVertex[x];
    for(auto it = M.lower_bound(l[i]); it != M.end() && it->first < r[i] && totalEdges < n; ++it){
      int j = it->second;
      adj[i].push_back(j);
      adj[j].push_back(i);
      ++totalEdges;
    }

    M[r[i]] = i;
  }

  printf("%s\n", totalEdges == n - 1 && DFS(1) == n ? "YES" : "NO");

  return 0;
}