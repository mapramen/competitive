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
#define N 300001

set<int> adj[N];
int a[N];
bool isMarked[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].insert(j);
  }

  int root = a[n];
  for(int i = 1; i <= n; ++i){
    isMarked[i] = adj[i].count(root) > 0;
  }

  int ans = 0;
  for(int i = n - 1, j = n - 1; i > 0; --i){
    if(!isMarked[a[i]]){
      continue;
    }
    int x = a[i], k = i + 1;
    for( ; k <= j && adj[x].count(a[k]) > 0; swap(a[k - 1], a[k]), ++k);
    if(j < k){
      ++ans;
      --j;
    }
  }

  printf("%d\n", ans);

  return 0;
}