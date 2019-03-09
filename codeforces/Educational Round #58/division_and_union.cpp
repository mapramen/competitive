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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define N 100001

set<int> S[2];
int ans[N];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    vector< tiii > v;
    scanf("%d", &n);
    for(int x = 1; x <= n; ++x){
      int l, r;
      scanf("%d%d", &l, &r);
      v.push_back(make_tuple(l, r, x));
    }
    sort(v.begin(), v.end());
    for(int x = 0, k = 0; x < n; k = 1 - k){
      int l, r, j;
      tie(l, r, j) = v[x];
      for( ; x < n; ++x){
        int lx, rx, i;
        tie(lx, rx, i) = v[x];
        if(lx <= r){
          S[k].insert(i);
          r = max(r, rx);
        }
        else{
          break;
        }
      }
    }
    if(S[0].empty() || S[1].empty()){
      printf("-1\n");
    }
    else{
      for(int k = 0; k < 2; ++k){
        for(int i : S[k]){
          ans[i] = 1 + k;
        }
      }
      for(int i = 1; i <= n; ++i){
        printf("%d ", ans[i]);
      }
      printf("\n");
    }
    for(int k = 0; k < 2; ++k){
      S[k].clear();
    }
  }
  return 0;
}