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
#define N 500001

vector< vector<int> > adj(N);
int l[N], r[N], timer = 1;

void DFS(int i, int p){
  for(int x = adj[i].size() - 1; x > -1; --x){
    int j = adj[i][x];
    if(j == p){
      continue;
    }
    l[j] = ++timer;
  }

  r[i] = ++timer;

  for(int x = 0; x < adj[i].size(); ++x){
    int j = adj[i][x];
    if(j == p){
      continue;
    }
    DFS(j, i);
  }
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

  l[1] = 1;
  DFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d %d\n", l[i], r[i]);
  }
  
  return 0;
}