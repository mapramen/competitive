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

vector<vector<int>> adj(N);
int dpUp[N], dpDown[N];

void DownDFS(int i, int p){
  int ans = 0;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DownDFS(j, i);
    ans = max(ans, 1 + dpDown[j]);
  }

  dpDown[i] = ans;
}

void UpDFS(int i, int p){
  int max1 = dpUp[i] - 1, max2 = max1;
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    if(dpDown[j] >= max1){
      max2 = max1, max1 = dpDown[j];
    }
    else if(dpDown[j] > max2){
      max2 = dpDown[j];
    }
  }

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    dpUp[j] = 2 + ((dpDown[j] == max1) ? max2 : max1);
    UpDFS(j, i);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DownDFS(1, 0);
  UpDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d ", max(dpDown[i], dpUp[i]));
  }
  printf("\n");

  return 0;
}