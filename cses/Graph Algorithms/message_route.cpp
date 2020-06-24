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

vector<vector<int>> adj(N);
int d[N], parent[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  queue<int> Q;
  Q.push(n);
  d[n] = 1;
  parent[n] = -1;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(parent[j] != 0){
        continue;
      }
      d[j] = 1 + d[i];
      parent[j] = i;
      Q.push(j);
    }
  }

  if(parent[1] == 0){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  printf("%d\n", d[1]);
  for(int i = 1; i != -1; i = parent[i]){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}