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

int a[N], b[N], c[N], r[N], targetFlowersLeft;
vector<int> removed;
bool kept[N];

void PreProcess(){
  for(int i = 1; i < N; ++i){
    if(c[i]){
      b[i] = c[i];
      ++targetFlowersLeft;
    }
    else{
      c[i] = N;
    }
  }
}

void Update(int i, int x){
  c[i] += x;
  if(x == 1 && c[i] == 1){
    ++targetFlowersLeft;
  }
  if(x == -1 && c[i] == 0){
    --targetFlowersLeft;
  }
}

void InitialiseAns(int l, int r, int k){
  for(int i = l; i <= r; ++i){
    if(b[a[i]]){
      kept[i] = true;
      --k;
      --b[a[i]];
    }
  }

  for(int i = l; i <= r && k > 0; ++i){
    if(kept[i]){
      continue;
    }
    kept[i] = true;
    --k;
  }
}

void ExtendAns(int l, int r, int n, int k){
  k *= n;
  for(int i = l; i <= r && k; ++i, --k){
    kept[i] = true;
  }
}

int main(){
  int m, k, n, s;

  scanf("%d%d%d%d", &m, &k, &n, &s);

  for(int i = 1; i <= m; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= s; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  PreProcess();

  for(int i = 1, j = 1; i <= m; ++i){
    j = max(j, i);
    for( ; j <= m && (j < i + k || targetFlowersLeft > 0); ++j){
      Update(a[j], -1);
    }
    r[i] = targetFlowersLeft > 0 ? N : j - 1;
    Update(a[i], 1);
  }

  bool found = false;
  for(int i = 1; i <= m && r[i] <= m && !found; ++i){
    int x = (i - 1) / k + 1 + (m - r[i]) / k;
    if(x < n){
      continue;
    }

    InitialiseAns(i, r[i], k);
    ExtendAns(1, i - 1, min(n - 1, (i - 1) / k), k);
    ExtendAns(r[i] + 1, m, n - min(n, (i - 1) / k + 1), k);
    found = true;
  }

  if(found){
    int s = 0;
    for(int i = 1; i <= m; ++i){
      s += !kept[i];
    }
    
    printf("%d\n", s);
    for(int i = 1; i <= m; ++i){
      if(!kept[i]){
        printf("%d ", i);
      }
    }
    printf("\n");
  }
  else{
    printf("-1\n");
  }

  return 0;
}