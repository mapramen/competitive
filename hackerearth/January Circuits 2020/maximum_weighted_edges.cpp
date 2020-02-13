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
#define N 100001

vector< vector<int> > adj(N);
int a[N], degree[N], ans[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ++degree[i], ++degree[j];
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  priority_queue<int> A;
  priority_queue< pii > Q;

  for(int i = 1; i <= n; ++i){
    A.push(a[i]);
    Q.push(make_pair(degree[i], i));
    ans[i] = -1;
  }

  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(ans[i] >= 0 || degree[i] != di){
      continue;
    }

    ans[i] = A.top();
    A.pop();

    for(int j : adj[i]){
      --degree[j];
      Q.push(make_pair(degree[i], i));
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}