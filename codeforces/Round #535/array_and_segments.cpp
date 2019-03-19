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
#define N 100002

vector< vector< pii > > segmentStart(N), segmentEnd(N);
int a[N], b[N];

int Relax(int i, int j, int k){
  for( ; i <= j; ++i){
    --b[i];
    k = min(k, b[i]);
  }
  return k;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    segmentStart[i].push_back(make_pair(j, x));
    segmentEnd[j].push_back(make_pair(i, x));
  }

  int ans = 0;
  vector<int> ansV, v;
  for(int i = 1, k = INT_MAX; i <= n; ++i){
    if(i != 1){
      if(ans < a[i] - k){
        ans = a[i] - k;
        ansV = v;
      }
    }
    b[i] = a[i];
    for(pii p : segmentEnd[i]){
      int j, x;
      tie(j, x) = p;
      k = Relax(j, i, k);
      v.push_back(x);
    }
    k = min(k, b[i]);
  }

  v.clear();
  for(int i = n, k = INT_MAX; i > 0; --i){
    if(i != n){
      if(ans < a[i] - k){
        ans = a[i] - k;
        ansV = v;
      }
    }
    b[i] = a[i];
    for(pii p : segmentStart[i]){
      int j, x;
      tie(j, x) = p;
      k = Relax(i, j, k);
      v.push_back(x);
    }
    k = min(k, b[i]);
  }

  printf("%d\n%lu\n", ans, ansV.size());
  for(int x : ansV){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}