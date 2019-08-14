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

int main(){
  int n, a, b, c;

  scanf("%d%d%d", &n, &a, &b);
  c = b;

  int ans = 0;
  for( ; n && (a + c); ++ans, --n){
    int x;
    scanf("%d", &x);

    if(x == 0){
      (c ? --c : --a);
    }
    else{
      if(a && c != b){
        --a, ++c;
      }
      else{
        (c ? --c : --a);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}