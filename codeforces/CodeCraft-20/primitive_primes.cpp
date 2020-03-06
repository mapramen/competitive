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

int GetDegree(int n, int p){
  int i;

  for(i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    if(x % p != 0){
      break;
    }
  }

  for(int j = i + 1; j < n; ++j){
    int x;
    scanf("%d", &x);
  }

  return i;
}

int main(){
  int n, m, p;
  
  scanf("%d%d%d", &n, &m, &p);
  
  int ans = GetDegree(n, p) + GetDegree(m, p);
  printf("%d\n", ans);
  
  return 0;
}