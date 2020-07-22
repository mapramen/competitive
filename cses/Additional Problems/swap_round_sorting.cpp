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

int a[N], pos[N];
bool visited[N];

int main(){
  int n;
  vector<vector<pii>> ans;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(true){
    for(int i = 1; i <= n; ++i){
      visited[i] = false;
    }

    vector<pii> ansx;

    for(int i = 1; i <= n; ++i){
      if(visited[i] || i == a[i]){
        continue;
      }

      vector<int> v;
      for(int j = i; !visited[j]; j = a[j]){
        visited[j] = true;
        v.push_back(j);
      }

      if(v.size() == 2){
        ansx.push_back({v.front(), v.back()});
        swap(a[v.front()], a[v.back()]);
      }
      else{
        for(int x = 0, y = v.size() - 1; y - x >= 2; ++x, --y){
          ansx.push_back({v[x], v[y - 1]});
          swap(a[v[x]], a[v[y - 1]]);
        }
      }

      v.clear();
    }

    if(ansx.empty()){
      break;
    }

    ans.push_back(ansx);
  }

  printf("%lu\n", ans.size());
  for(auto v: ans){
    printf("%lu\n", v.size());
    for(pii p: v){
      printf("%d %d\n", p.first, p.second);
    }
  }

  return 0;
}