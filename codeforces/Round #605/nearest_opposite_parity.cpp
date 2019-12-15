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

vector< vector<int> > adj(N);
int a[N], d[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    d[i] = -1;
    int x = a[i];
    
    for(int j = i - x, k = 0; j <= n && k < 2; j += 2 * x, ++k){
      if(j <= 0){
        continue;
      }

      if(a[j] % 2 != a[i] % 2){
        d[i] = 1;
        Q.push(i);
      }
      else{
        adj[j].push_back(i);
      }
    }
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j : adj[i]){
      if(d[j] != -1){
        continue;
      }
      d[j] = 1 + d[i];
      Q.push(j);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", d[i]);
  }
  printf("\n");
  
  return 0;
}