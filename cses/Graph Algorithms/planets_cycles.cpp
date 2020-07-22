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

int parent[N], pos[N], ans[N];
bool visited[N], calculated[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &parent[i]);
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }

    int j = i;
    vector<int> v;

    for( ; !visited[j]; j = parent[j]){
      visited[j] = true;
      pos[j] = v.size();
      v.push_back(j);
    }

    if(!calculated[j]){
      int c = v.size() - pos[j];
      for( ; v.size() > pos[j]; v.pop_back()){
        int k = v.back();
        ans[k] = c;
        calculated[k] = true;
      }
    }

    for( ; !v.empty(); v.pop_back()){
      int k = v.back();
      ans[k] = 1 + ans[parent[k]];
      calculated[k] = true;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}