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

int a[N], b[N], ans[N];
vector<vector<pii>> V(N);
priority_queue<pii, vector<pii>, greater<pii>> Q;
vector<pii> possibleSwaps;

bool Check(int i){
  return a[i] <= ans[i] && ans[i] <= b[i];
}

void PrintOrdering(int n){
  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    V[l].push_back({r, i});
    a[i] = l, b[i] = r;
  }

  for(int x = 1; x <= n; ++x){
    for(auto p : V[x]){
      Q.push(p);
    }

    auto [r, i] = Q.top();
    Q.pop();

    ans[i] = x;

    if(!Q.empty()){
      possibleSwaps.push_back({i, Q.top().second});
    }
  }

  while(!possibleSwaps.empty()){
    auto [i, j] = possibleSwaps.back();
    swap(ans[i], ans[j]);

    if(Check(i) && Check(j)){
      break;
    }

    swap(ans[i], ans[j]); 
    possibleSwaps.pop_back();
  }

  printf("%s\n", possibleSwaps.empty() ? "YES" : "NO");
  PrintOrdering(n);

  if(!possibleSwaps.empty()){
    auto [i, j] = possibleSwaps.back();
    swap(ans[i], ans[j]);
    PrintOrdering(n);
  }

  return 0;
}