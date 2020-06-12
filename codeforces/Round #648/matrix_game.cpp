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
#define N 51

bool rows[N], columns[N];

string Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    rows[i] = false;
  }

  for(int j = 1; j <= m; ++j){
    columns[j] = false;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x;
      scanf("%d", &x);
      if(x){
        rows[i] = true, columns[j] = true;
      }
    }
  }

  int r = 0, c = 0;
  for(int i = 1; i <= n; ++i){
    r += (!rows[i]);
  }

  for(int j = 1; j <= m; ++j){
    c += (!columns[j]);
  }

  int ans = min(r, c);

  return ans % 2 == 1 ? "Ashish" : "Vivek";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}