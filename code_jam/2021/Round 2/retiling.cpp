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
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define N 10

char S[N][N + 1], T[N][N + 1];
vector<pii> A, B;

ll MinCostMatching(const vvl &cost, vi &Lmate, vi &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  vl u(n);
  vl v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = vi(n, -1);
  Rmate = vi(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (cost[i][j] - u[i] - v[j] < 0) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }
  
  vl dist(n);
  vi dad(n);
  vi seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	const ll new_dist = dist[j] + cost[i][k] - u[i] - v[k];
	if (dist[k] > new_dist) {
	  dist[k] = new_dist;
	  dad[k] = j;
	}
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  ll value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}

void Read(char s[][N + 1], int n, int m){
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }
}

void InitialiseGroups(int n, int m){
  A.clear();
  B.clear();

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(S[i][j] == T[i][j]){
        continue;
      }
      if(S[i][j] == 'M'){
        A.push_back({i, j});
      }
      else{
        B.push_back({i, j});
      }
    }
  }

  if(A.size() < B.size()){
    swap(A, B);
  }
}

int Compute(int f, int s){
  int n = A.size(), m = B.size();

  vvl cost(n, vl(n));
  vi lMate(n), rMate(n);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cost[i][j] = min(2 * f, s * (abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second)));
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = m; j < n; ++j){
      cost[i][j] = f;
    }
  }

  return MinCostMatching(cost, lMate, rMate);
}

int Solve(){
  int n, m, f, s;
  scanf("%d%d%d%d", &n, &m, &f, &s);

  Read(S, n, m);
  Read(T, n, m);
  InitialiseGroups(n, m);

  return Compute(f, s);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}