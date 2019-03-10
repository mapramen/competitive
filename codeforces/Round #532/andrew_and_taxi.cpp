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
#define N 100001

vector< vector<int> > edges(N);
int v[N], w[N], inDegree[N], topologicalOrderPosition[N];
vector<int> weights(1);

bool Check(int n, int m){
  for(int i = 1; i <= n; ++i){
    inDegree[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    for(int e : edges[i]){
      if(w[e] > m){
        ++inDegree[v[e]];
      }
    }
  }

  int pos = 0;
  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    if(inDegree[i] == 0){
      Q.push(i);
      topologicalOrderPosition[i] = ++pos;
    }
  }

  int left = n;
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    --left;

    for(int e : edges[i]){
      if(w[e] <= m){
        continue;
      }
      int j = v[e];
      --inDegree[j];
      if(inDegree[j] == 0){
        Q.push(j);
        topologicalOrderPosition[j] = ++pos;
      }
    }
  }

  return left == 0;
}

int BinarySearch(int n){
  sort(weights.begin(), weights.end());
  int x = 0, y = weights.size() - 1, ans = weights.back();
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, weights[mid])){
      ans = weights[mid], y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int e = 1; e <= m; ++e){
    int i;
    scanf("%d%d%d", &i, &v[e], &w[e]);
    edges[i].push_back(e);
    weights.push_back(w[e]);
  }

  int ans = BinarySearch(n);
  Check(n, ans);

  vector<int> V;
  for(int i = 1; i <= n; ++i){
    for(int e : edges[i]){
      if(w[e] > ans){
        continue;
      }
      int j = v[e];
      if(topologicalOrderPosition[j] < topologicalOrderPosition[i]){
        V.push_back(e);
      }
    }
  }

  printf("%d %lu\n", ans, V.size());
  for(int e : V){
    printf("%d ", e);
  }
  printf("\n");

  return 0;
}