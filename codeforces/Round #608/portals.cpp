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
#define N 5001

vector< vector<int> > portals(N);
int a[N], b[N], c[N], lastPortal[N];
multiset<int> S;

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    lastPortal[i] = i;
  }

  while(m--){
    int u, v;
    scanf("%d%d", &u, &v);
    lastPortal[v] = max(lastPortal[v], u);
  }

  for(int i = 1; i <= n; ++i){
    portals[lastPortal[i]].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    for( ; k < a[i] && !S.empty(); ++k){
      S.erase(S.begin());
    }

    if(k < a[i]){
      printf("-1\n");
      return 0;
    }

    k += b[i];
    for(int j : portals[i]){
      S.insert(c[j]);
      --k;
    }

    for( ; k < 0 && !S.empty(); ++k){
      S.erase(S.begin());
    }
  }

  int ans = 0;
  for(int x : S){
    ans += x;
  }

  printf("%d\n", ans);

  return 0;
}