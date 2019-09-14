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
#define N 100002

bool visited[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  vector< pii > v;
  while(m--){
    int x;
    scanf("%d", &x);

    for(int k = -1, y = x - 1; k < 2; k += 2, y += 2){
      if(visited[y]){
        v.push_back(make_pair(x, y));
      }
    }
    
    v.push_back(make_pair(x, x));
    visited[x] = true;
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int ans = 3 * n - 2 - v.size();

  printf("%d\n", ans);

  return 0;
}