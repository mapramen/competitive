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
#define B 18

vector<int> v{3, 4, 5, 7, 11, 13, 17};

int Query(int m){
  for(int i = 0; i < B; ++i){
    printf("%d ", m);
  }
  printf("\n");
  fflush(stdout);
  int x = 0;
  for(int i = 0; i < B; ++i){
    int a;
    scanf("%d", &a);
    x = (x + a) % m;
  }
  return x;
}

void Solve(int m){
  vector<int> u;
  for(int i : v){
    int r = Query(i);
    u.push_back(r);
  }

  int ans;
  for(int i = 1; i <= m; ++i){
    bool valid = true;
    for(int j = 0; j < v.size() && valid; ++j){
      valid = (i % v[j] == u[j]);
    }
    if(valid){
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);
  fflush(stdout);

  scanf("%d", &ans);
}

int main(){
  int t, n, m;
  scanf("%d%d%d", &t, &n, &m);
  for(int i = 1; i <= t; ++i){
    Solve(m);
  }
  return 0;
}