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
 
map<int,int> M;
 
int ExtractJustLower(int x){
  if(M.empty() || x < M.begin()->first){
    return -1;
  }

  auto it = prev(M.upper_bound(max(0, x)));
  if(it->second == 1){
    M.erase(it);
  }
  else{
    --(it->second);
  }

  return it->first;
}
 
int main(){
  int n, m;
 
  scanf("%d%d", &n, &m);
 
  while(n--){
    int x;
    scanf("%d", &x);
    ++M[x];
  }
 
  while(m--){
    int x;
    scanf("%d", &x);
    printf("%d\n", ExtractJustLower(x));
  }
 
  return 0;
}