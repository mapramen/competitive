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

int a[N], b[N];
priority_queue<int> Q;
set<int> P;
char s[N];

void AssignTeam(int i, int x){
  s[i] = '1' + x;
  b[a[i]] = -1;
  P.erase(i);
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
    b[a[i]] = i;
    Q.push(a[i]);
    P.insert(i);
  }

  int cur = 0;
  while(!Q.empty()){
    int x = Q.top();
    Q.pop();

    if(b[x] == -1){
      continue;
    }

    int i = b[x];
    AssignTeam(i, cur);

    for(int j = k; j > 0; --j){
      auto it = P.upper_bound(i);
      if(it == P.end()){
        break;
      }
      AssignTeam(*it, cur);
    }

    for(int j = k; j > 0; --j){
      auto it = P.lower_bound(i);
      if(it == P.begin()){
        break;
      }
      AssignTeam(*prev(it), cur);
    }

    cur = 1 - cur;
  }

  printf("%s\n", s);

  return 0;
}