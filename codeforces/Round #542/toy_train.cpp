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

int a[N], b[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i){
    b[i] = i + n - 1;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    --i, --j;
    if(j < i){
      j += n;
    }
    ++a[i];
    b[i] = min(b[i], j);
  }

  for(int i = 0; i < n; ++i){
    int ans = 0;
    for(int j = i; j < i + n; ++j){
      int k = j % n;
      if(a[k] == 0){
        continue;
      }
      int ansx = j - i + (a[k] - 1) * n + b[k] - k;
      ans = max(ans, ansx);
    }
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}