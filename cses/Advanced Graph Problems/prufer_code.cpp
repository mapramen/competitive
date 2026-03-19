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

int d[N];
priority_queue<int,vector<int>,greater<int>> Q;

void CheckAndPush(int i){
  if(d[i] == 1){
    Q.push(i);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  
  vector<int> a(n - 2);
  for(int i = 0; i < n - 2; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    d[i] = 1;
  }

  for(int i: a){
    ++d[i];
  }

  for(int i = 1; i <= n; ++i){
    CheckAndPush(i);
  }

  for(int j: a){
    int i = Q.top();
    Q.pop();

    printf("%d %d\n", i, j);

    --d[i], --d[j];
    CheckAndPush(j);
  }

  for(int i = 1; i < n; ++i){
    if(d[i] == 1){
      printf("%d %d\n", i, n);
    }
  }

  return 0;
}