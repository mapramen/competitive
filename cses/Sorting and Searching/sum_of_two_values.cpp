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

int main(){
  int n, s;
  map<int,int> M;

  scanf("%d%d", &n, &s);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    auto it = M.find(s - x);
    if(it != M.end()){
      printf("%d %d\n", it->second, i);
      return 0;
    }

    M[x] = i;
  }

  printf("IMPOSSIBLE\n");

  return 0;
}