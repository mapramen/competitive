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

int c[N], f[N];

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    int n;
    vector<int> v;
    vector< pii > V(1);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
      int x, y;
      scanf("%d%d", &x, &y);
      v.push_back(x);
      ++c[x];
      f[x] += y;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i : v){
      V.push_back(make_pair(c[i], f[i]));
    }
    sort(V.begin(), V.end());

    int a = 0, b = 0;
    priority_queue<int> Q;

    for(int m = n; m; ){
      if(V.back().first < m){
        if(!Q.empty()){
          a += m;
          b += min(m, Q.top());
          Q.pop();
        }
        --m;
      }
      else{
        Q.push(V.back().second);
        V.pop_back();
      }
    }

    
    printf("%d %d\n", a, b);

    for(int i : v){
      c[i] = 0;
      f[i] = 0;
    }
  }

  return 0;
}