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
#define tiii tuple<int,int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int color[N], degree[N];
deque<tiii> Q;

int ReadInputs(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &color[i]);
  }
  
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return n;
}

void CheckAndEnqueue(int i, int c, int k){
  if(degree[i] != 1){
    return;
  }

  if(color[i] == 0 || color[i] == c){
    Q.push_front({i, c, k});
  }
  else{
    Q.push_back({i, color[i], k + 1});
  }
}

int CalculateAns(int n, int c){
  if(n == 1){
    return 1;
  }

  for(int i = 1; i <= n; ++i){
    degree[i] = adj[i].size();
  }

  int k = 1;
  for(int i = 1; i <= n; ++i){
    CheckAndEnqueue(i, c, k);
  }

  while(!Q.empty()){
    int i;
    tie(i, c, k) = Q.front();
    Q.pop_front();

    for(int j: adj[i]){
      --degree[j];
      CheckAndEnqueue(j, c, k);
    }
  }

  return k;
}

int Solve(){
  int n = ReadInputs();
  return min(CalculateAns(n, 1), CalculateAns(n, 2));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}