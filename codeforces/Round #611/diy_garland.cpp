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
#define N 200001

int a[N], b[N], outDegree[N];
priority_queue< pii, vector< pii >, greater< pii > > Q;
vector< pii > edges;

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    scanf("%d", &a[x]);
    ++outDegree[a[x]];
  }

  for(int i = 1; i <= n; ++i){
    b[i] = i;
    if(outDegree[i] == 0){
      Q.push(make_pair(b[i], i));
    }
  }

  for(int x = n - 1; x > 0; --x){
    int i = a[x];

    if(Q.empty()){
      edges.clear();
      break;
    }

    int p, j;
    tie(p, j) = Q.top();
    Q.pop();

    b[i] = max(b[i], p);
    edges.push_back(make_pair(i, j));
    
    if(--outDegree[i] == 0){
      Q.push(make_pair(b[i], i));
    }
  }

  if(edges.empty()){
    printf("-1\n");
    return 0;
  }

  printf("%d\n", Q.top().second);
  for(auto edge : edges){
    printf("%d %d\n", edge.first, edge.second);
  }
  
  return 0;
}