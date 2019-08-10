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
#define N 300001

vector< vector<int> > adj(N);
int a[N];

int DFS(int i){
  if(adj[i].size() == 0){
    return 1;
  }

  int ans = a[i] ? INT_MAX : 0;
  
  for(int j : adj[i]){
    if(a[i]){
      ans = min(ans, DFS(j));
    }
    else{
      ans += DFS(j);
    }
  }
  
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (adj[i].size() == 0);
  }

  ans -= (DFS(1) - 1);

  printf("%d\n", ans);

  return 0;
}