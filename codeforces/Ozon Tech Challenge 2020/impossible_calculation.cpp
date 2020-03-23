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
#define M 1001

int a[M];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  
  if(n > m){
    printf("0\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  
  int ans = 1;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ans = (ans * (abs(a[j] - a[i]) % m)) % m;
    }
  }

  printf("%d\n", ans);

  return 0;
}