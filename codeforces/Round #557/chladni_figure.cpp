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

vector< vector<int> > segments(N), C;
int n, a[2 * N], f[2 * N];

void AddSegment(int i, int j){
  j = (n + j - i) % n;
  segments[i].push_back(j);
}

void ComputeFailure(int i){
  int &k = f[i];
  k = f[i - 1];
  for( ; k && a[k + 1] != a[i]; k = f[k]);
  k += (a[k + 1] == a[i]);
}

int main(){
  int m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    AddSegment(i, j);
    AddSegment(j, i);
  }

  C.push_back(vector<int>());
  for(int i = 1; i <= n; ++i){
    sort(segments[i].begin(), segments[i].end());
    C.push_back(segments[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), segments[i]) - C.begin();
  }

  for(int i = n + 1, j = 1; j < n; ++i, ++j){
    a[i] = a[j];
  }

  for(int i = 2; i < 2 * n; ++i){
    ComputeFailure(i);
    if(f[i] == n){
      printf("YES\n");
      return 0;
    }
  }

  printf("NO\n");
  return 0;
}