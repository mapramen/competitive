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
#define tlll tuple< ll, ll, ll >
#define N 200001

int n, k;
vector< vector<int> > v(N);
ll a[N], b[N], c[N];

ll GetDischargeTime(ll x, ll y){
  return 1 + (x / y);
}

void AddToDischargeList(int i){
  ll t = GetDischargeTime(c[i], b[i]);
  if(t < k){
    v[t].push_back(i);
  }
}

bool Check(ll m){
  for(int i = 0; i < k; ++i){
    v[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    c[i] = a[i];
    AddToDischargeList(i);
  }

  for(int i = 0, j = 0; i < k; ++i){
    for(j = max(j, i); j < k && v[j].size() == 0; ++j);
    
    if(j == i){
      return false;
    }

    if(j == k){
      break;
    }

    int x = v[j].back();
    v[j].pop_back();
    c[x] += m;
    AddToDischargeList(x);
  }

  return true;
}

ll BinarySearch(){
  ll x = 0, y = 1E13, ans = -1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  scanf("%d%d", &n, &k);
  
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &b[i]);
  }

  printf("%lld\n", BinarySearch());

  return 0;
}