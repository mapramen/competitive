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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

typedef long long ll;

typedef
tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  // This policy updates nodes' metadata for order statistics.
  tree_order_statistics_node_update>
set_t;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
set_t S;
char ch[2];

ll GetMappedValue(int i, int x){
  return 1ll * x * N + i;
}

void Add(int i, int x){
  S.insert(GetMappedValue(i, x));
}

void Delete(int i, int x){
  S.erase(GetMappedValue(i, x));
}

void Update(int i, int x){
  Delete(i, a[i]);
  Add(i, x);
  a[i] = x;
}

int Query(int i){
  return S.order_of_key(GetMappedValue(0, i + 1));
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    Add(i, a[i]);
  }

  while(q--){
    scanf("%s", ch);

    if(ch[0] == '!'){
      int i, x;
      scanf("%d%d", &i, &x);
      Update(i, x);
    }
    else{
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", Query(l, r));
    }
  }
  
  return 0;
}