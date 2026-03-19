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
#define N 100001

vector<vector<int>> adj(N);
int degree[N];
priority_queue<int> Q;

void CheckAndPush(int i){
  if(degree[i] == 0){
    Q.push(i);
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &j, &i);
    adj[i].push_back(j);
    ++degree[j];
  }

  for(int i = 1; i <= n; ++i){
    CheckAndPush(i);
  }

  vector<int> ans;
  while(!Q.empty()){
    int i = Q.top();
    Q.pop();
    ans.push_back(i);
    for(int j: adj[i]){
      --degree[j];
      CheckAndPush(j);
    }
  }
  reverse(ans.begin(), ans.end());

  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}