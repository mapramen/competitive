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
#define N 200001

int T[N];

void Reset(){
  for(int i = 1; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll SortingMethod1(vector<int> a){
  Reset();
  ll ans = 0;
  for(int i = 0; i < a.size(); ++i){
    ans += (i - Query(a[i]));
    Update(a[i], 1);
  }
  return ans;
}

int SortingMethod2(vector<int> a){
  for(int i = 0; i < a.size(); ++i){
    --a[i];
  }

  int ans = 0;
  for(int i = 0; i < a.size(); ++i){
    if(a[i] == -1){
      continue;
    }
    
    vector<int> v{i};
    for(int j = a[i]; j != i; j = a[j]){
      v.push_back(j);
    }

    for(int j: v){
      a[j] = -1;
    }
    v.clear();

    ++ans;
  }

  return a.size() - ans;
}

int SortingMethod3(vector<int> a){
  vector<int> v;

  for(int x: a){
    if(v.empty() || v.back() < x){
      v.push_back(x);
      continue;
    }

    int i = lower_bound(v.begin(), v.end(), x) - v.begin();
    v[i] = x;
  }

  int ans = a.size() - v.size();
  v.clear();

  return ans;
}

int SortingMethod4(vector<int> a){
  Reset();

  int ans = 0;
  for(int n = a.size(); n != 0; --n){
    int i = T[n] == 1 ? 0 : n;

    for( ; !a.empty() && a.back() != i; a.pop_back()){
      T[a.back()] = 1;
      ++ans;
    }
    
    if(!a.empty()){
      a.pop_back();
    }
  }

  return ans;
}

int main(){
  int n;
  vector<int> a;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }

  printf("%lld %d %d %d\n", SortingMethod1(a), SortingMethod2(a), SortingMethod3(a), SortingMethod4(a));

  return 0;
}